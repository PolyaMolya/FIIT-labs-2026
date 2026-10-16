#include <stdio.h>

int main(){
	double dsp, dvp, wood;
	printf("Enter density (g/cm3): dsp dvp wood\n");
	if (scanf_s("%lf %lf %lf", &dsp, &dvp, &wood) != 3) {
		printf("Error: enter numbers only\n");
		return 1;
	}
	if ((dsp <= 0) || (dvp <= 0) || (wood <= 0)) {
		printf("Error: densities must be greater than 0\n");
		return 1;
	}
	double t=1.5, tBW= 0.5, tD = 1.0;
	double h, w, d;
	printf("Enter sizes (cm): height width depth\n");
	if (scanf_s("%lf %lf %lf", &h, &w, &d) != 3) {
		printf("Error: enter numbers only\n");
		return 1;
	}
	if ((h <= 0) || (w <= 0) || (d <= 0)) {
		printf("Error: sizes must be greater than 0\n");
		return 1;
	}
	int n = 0;
	double count = 40.0;
	while (count < h) {
		n++;
		count += 40.0;
	}
	double vBW, vSIDES, vTAB, vD, vS, mBW, mSIDES, mTAB, mD, mS, M;
	vBW = h * w * tBW;
	vSIDES = h * d * t * 2.0;
	vTAB = w * d * t * 2.0;
	vD = h * w * tD;
	vS = d * (w - t*2.0) * t * n;
	mBW = vBW * dvp;
	mSIDES = vSIDES * dsp;
	mTAB = vTAB * dsp;
	mD = vD * wood;
	mS = vS * dsp;
	M = mBW + mSIDES + mTAB + mD + mS;
	printf("Cabinet mass (g): %lf\n", M);
	return 0;
}
