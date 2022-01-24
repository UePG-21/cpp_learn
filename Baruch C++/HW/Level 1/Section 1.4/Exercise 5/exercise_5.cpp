#include <stdio.h>

int main()
{
	double start_temp_C = 0.0; // start degrees Celsius temperature
	double end_temp_C = 19.0; // end degrees Celsius temperature
	double step_C = 1.0; // step size of the degrees Celsius temperature
	double temp_C; // temperature in Celsius
	double temp_F; // temperature in Fahrenheit

	// print header text
	printf("%10s%15s\n", "Celsius", "Fahrenheit");

	for (temp_C = start_temp_C; temp_C <= end_temp_C; temp_C+=step_C)
	{
		// convert temperature in Celsius to temperature in Fahrenheit
		temp_F = temp_C * 9.0 / 5.0 + 32.0;

		// print both temperatures
		printf("%10.0f%15.1f\n", temp_C, temp_F);
	}

    return 0;
}