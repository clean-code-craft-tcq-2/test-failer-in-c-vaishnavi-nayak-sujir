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
    
}

float convertFarenheitToCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}
void alertInCelcius(float celcius,int (*fnPtrForNetworkAlert)(float)) {
    int returnCode = (*fnPtrForNetworkAlert)(celcius);
    if (returnCode != 200) {
        alertFailureCount += 1;
    }
}

void testcode_main(){
	
	int (*fnPtrForNetworkAlert)(float) = networkAlertStub;
	float temp_celcius = convertFarenheitToCelcius(400.5);
    alertInCelcius(temp_celcius,fnPtrForNetworkAlert);
	assert(alertFailureCount==1);
	temp_celcius = convertFarenheitToCelcius(303.6);
    alertInCelcius(temp_celcius,fnPtrForNetworkAlert);
	assert(alertFailureCount==1);
	temp_celcius = convertFarenheitToCelcius(500.6);
    alertInCelcius(temp_celcius,fnPtrForNetworkAlert);
	assert(alertFailureCount==2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
}


int main() {
	test_code_main();
	// production code can be added here. Test code is isolated
    return 0;
}
