#include <stdio.h>

int main()
{
	double start_temp_F = 0.0; // start degrees Fahrenheit temperature
	double end_temp_F = 300.0; // end degrees Fahrenheit temperature
	double step_F = 20.0; // step size of the degrees Fahrenheit temperature
	double temp_F = NULL; // temperature in Fahrenheit
	double temp_C = NULL; // temperature in Celsius

	// start the loop from the start temperature in Fahrenheit
	temp_F = start_temp_F;

	// print header text.
	printf("%10s%10s\n","Fahrenheit", "Celsius");

	while (temp_F <= end_temp_F)
	{
		// convert temperature in Fahrenheit to temperature in Celsius
		temp_C = (5.0 / 9.0) * (temp_F - 32.0);

		// print both temperatures
		printf("%10.0f%10.1f\n", temp_F, temp_C);

		// move on to the next temperature in Fahrenheit
		temp_F += step_F;
	}

    return 0;
}