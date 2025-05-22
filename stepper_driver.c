


int stepposition = 0; //set to zero
int stepposition2 = 0;
//confusing but clean
void setStep(int a1, int b1, int a2, int b2){
    gpio_put(A1, a1);
    gpio_put(B1, b1);
    gpio_put(A2, a2);
    gpio_put(B2, b2);
}
void setStep2(int a11, int b11, int a22, int b22){
    gpio_put(A11, a11);
    gpio_put(B11, b11);
    gpio_put(A22, a22);
    gpio_put(B22, b22);
}
//this void loop allows a linear drive from its prevoius pin state
void stepperL(){
    stepposition = (stepposition - 1 + 4) % 4; //move prev and wrap
    switch(stepposition){ 
        case 0: setStep(1, 0, 0, 1); break;
        case 1: setStep(0, 0, 1, 1); break;
        case 2: setStep(0, 1, 1, 0); break;
        case 3: setStep(1, 1, 0, 0); break;
    }

}
void stepperR(){
    stepposition = (stepposition + 1) % 4; //move prev and wrap
    switch(stepposition){ 
        case 0: setStep(1, 0, 0, 1); break;
        case 1: setStep(0, 0, 1, 1); break;
        case 2: setStep(0, 1, 1, 0); break;
        case 3: setStep(1, 1, 0, 0); break;
    }
}
//this void loop allows a linear drive from its prevoius pin state for motor2 yay..
void stepperL2(){
    stepposition2 = (stepposition2 - 1 + 4) % 4; //move prev and wrap
    switch(stepposition2){ 
        case 0: setStep2(1, 0, 0, 1); break;
        case 1: setStep2(0, 0, 1, 1); break;
        case 2: setStep2(0, 1, 1, 0); break;
        case 3: setStep2(1, 1, 0, 0); break;
    }

}
void stepperR2(){
    stepposition2 = (stepposition2 + 1) % 4; //move prev and wrap
    switch(stepposition2){ 
        case 0: setStep2(1, 0, 0, 1); break;
        case 1: setStep2(0, 0, 1, 1); break;
        case 2: setStep2(0, 1, 1, 0); break;
        case 3: setStep2(1, 1, 0, 0); break;
    }
}