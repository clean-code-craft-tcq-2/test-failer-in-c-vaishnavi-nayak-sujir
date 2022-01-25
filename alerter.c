#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
int threshold=200;//let threshold be 200 deg celcius
int networkAlertStub(float celcius) {

    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
	if(celcius >= threshold)
	{
		return 500;
	}
	else
	{
		return 200;
	}
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}
int checkerror(float farenheit){
	float celcius = (farenheit - 32) * 5 / 9;
	if (celcius >=threshold)// if temp is greater than threshold alertcounter should increment
	{
		assert(alertFailureCount>0);
	}
}

int main() {
    alertInCelcius(400.5);
	checkerror(400.5);
    alertInCelcius(303.6);
	checkerror(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
