void fft(float data_re[], float data_im[], const unsigned int N)
{
  rearrange(data_re, data_im, N);
  compute(data_re, data_im, N);
}

void rearrange(float data_re[], float data_im[], const unsigned int N)
{
  unsigned int target = 0;
  for (unsigned int position=0; position<N; position++)
  {
    if (target > position)
    {
	const float temp_re = data_re[target];
	const float temp_im = data_im[target];
	data_re[target] = data_re[position];
	data_im[target] = data_im[position];
	data_re[position] = temp_re;
	data_im[position] = temp_im;
    }
  unsigned int mask = N;
  while (target & (mask >>=1))
  {
    target &= ~mask;
  }
    target |= mask;
  }
}

void compute(float data_re[], float data_im[], const unsigned int N)
{
  const float pi = -3.14159265358979323846;

  for (unsigned int step=1; step<N; step <<= 1)
  {
    const unsigned int jump = step << 1;
    const float step_d = (float) step;
    float twiddle_re = 1.0;
    float twiddle_im = 0.0;
    for(unsigned int group=0; group<step; group++)
    {
	  for (unsigned int pair=group; pair<N; pair+=jump)
	  {
	    const unsigned int match = pair + step;
	    const float product_re = twiddle_re*data_re[match]-twiddle_im*data_im[match];
	    const float product_im = twiddle_im*data_re[match]+twiddle_re*data_im[match];
	    data_re[match] = data_re[pair]-product_re;
	    data_im[match] = data_im[pair]-product_im;
	    data_re[pair] += product_re;
	    data_im[pair] += product_im;
	  }

	// we need the factors below for the next iteration
	// if we don't iterate then don't compute

	if (group+1 == step)
	{
      continue;
	}

	float angle = pi*((float) group+1)/step_d;
	twiddle_re = cos(angle);

    }
  }
}


void remove_frec(float data_re[],float data_im[],float data_res_re[],float data_res_im[], int N){

	for(int i = 0 ; i < N; ++i){
		data_res_re[i] = data_re[i];
		data_res_im[i] = data_im[i];
	}

}



void ifft(float data_real[], float data_imag[], int N)
{
    float temp1_real;
	float temp1_imag;
    float temp2_real;
    float temp2_imag;
    int i, j, k;
    int upper_leg, lower_leg;
    int leg_diff;
    int num_stages = 0;
    int index, step;

    i = 1;
    do
    {
        num_stages += 1;
        i = i * 2;
    } while (i != N);


    leg_diff = N / 2;

    step = 256 / N;


    for (i = 0; i < num_stages; i++)
    {
        index = 0;
        for (j = 0; j < leg_diff; j++)
        {
            for (upper_leg = j; upper_leg < N; upper_leg += (2 * leg_diff))
            {
                lower_leg = upper_leg + leg_diff;
                temp1_real = data_real[upper_leg] + data_real[lower_leg];
                temp1_imag = data_imag[upper_leg] + data_imag[lower_leg];
                temp2_real = data_real[upper_leg] - data_real[lower_leg];
                temp2_imag = data_imag[upper_leg] - data_imag[lower_leg];
                data_real[upper_leg] = temp1_real;
                data_imag[upper_leg] = temp1_imag;
            }
            index += step;
        }
        leg_diff = leg_diff / 2;
        step *= 2;
    }

    j = 0;
    for (i = 1; i < (N - 1); i++)
    {
        k = N / 2;
        while (k <= j)
        {
            j = j - k;
            k = k / 2;
        }
        j = j + k;
        if (i < j)
        {
            temp1_real = data_real[j];
            temp1_imag = data_imag[j];
            data_real[j] = data_real[i];
            data_imag[j] = data_imag[i];
            data_real[i] = temp1_real;
            data_imag[i] = temp1_imag;
        }
    }
    return;
}
