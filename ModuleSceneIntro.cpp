#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	
	Floor.color = Grey;
	Floor.size = { 10000,0,10000 };
	Floor.SetPos(0, 0, 0);

	//---------PowerUps
	AddPowerUp(3, 3, 3, 30, 1, 123, 0); 
	//--------- Sensors
	int j = 0;
	AddSens(2, 6, 40, 70, 1, 123, j++);
	AddSens(2, 6, 40, 120, 1, 123, j++);
	actual.Stop();
	//track
	int i = 0;
	//recta ext
	AddWall(10, 2, 1, 5.76, 1, 34.87, i++, 24.341);
	AddWall(10, 2, 1, 14.68, 1, 30.83, i++, 24.341);
	AddWall(10, 2, 1, 23.59, 1, 26.88, i++, 24.341);
	AddWall(10, 2, 1, 32.51, 1, 22.85, i++, 24.341);
	AddWall(10, 2, 1, 41.61, 1, 18.9, i++, 24.502);
	AddWall(10, 2, 1, 50.54, 1, 14.86, i++, 25.058);
	AddWall(10, 2, 1, 59.38, 1, 10.57, i++, 26.495);
	AddWall(10, 2, 1, 68.44, 1, 6.74, i++, 18.773);
	AddWall(10, 2, 1, 78.29, 1, 395, i++, 13.12);
	AddWall(10, 2, 1, 87.97, 1, 2.16, i++, 6.278);
	AddWall(10, 2, 1, 92.99f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 102.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 112.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 122.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 132.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 142.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 152.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 162.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 172.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 182.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 192.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 202.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 212.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 222.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 232.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 242.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 252.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 262.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 272.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 282.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 292.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 302.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 312.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 322.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 332.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 342.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 352.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 362.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 372.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 382.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 391.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 401.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 411.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 421.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 431.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 441.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 451.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 461.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 471.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 481.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 491.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 501.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 511.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 521.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 531.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 541.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 551.781f, 1, 1.072f, i++);
	AddWall(10, 2, 1, 561.781f, 1, 1.072f, i++);
	//curva 1 (chicana) ext
	AddWall(10, 2, 1, 576.59f, 1, 2.09f, i++, -6.615f);
	AddWall(10, 2, 1, 586.22f, 1, 4.8f, i++, -23.786);
	AddWall(10, 2, 1, 594.8f, 1, 9.98, i++, -38.184);
	AddWall(10, 2, 1, 600.59, 1, 17.99, i++, -69.129);
	AddWall(10, 2, 1, 603.56f, 1, 27.57, i++, -77.172);
	AddWall(10, 2, 1, 608.8f, 1, 37.32, i++, -76.59);
	AddWall(10, 2, 1, 608.16, 1, 47.03, i++, -75.472);
	AddWall(10, 2, 1, 610.84, 1, 56.59, i++, -72.61);
	//curva 2 (chicana) ext
	AddWall(10, 2, 1, 614.01, 1, 66.07, i++, -70.846);
	AddWall(10, 2, 1, 617.8, 1, 75.25, i++, -64.433);
	AddWall(10, 2, 1, 622.61, 1, 83.93, i++, -57.695);
	AddWall(10, 2, 1, 628.54, 1, 92.01, i++, -50.16);
	AddWall(10, 2, 1, 635.51, 1, 98.54, i++, -36.705);
	AddWall(10, 2, 1, 643.79, 1, 104.04, i++, -30.548);
	AddWall(10, 2, 1, 652.82, 1, 107.72, i++, -14.036);
	AddWall(10, 2, 1, 662.68, 1, 109.49, i++, -6.846);
	AddWall(10, 2, 1, 672.58, 1, 110.71, i++, -7.304);
	AddWall(10, 2, 1, 682.54, 1, 111.7, i++, -4.203);
	AddWall(10, 2, 1, 692.49, 1, 112.25, i++, -2.203);
	AddWall(10, 2, 1, 702.49, 1, 112.58, i++, -2.203);
	AddWall(10, 2, 1, 712.49, 1, 112.97, i++, -2.203);
	AddWall(10, 2, 1, 722.5, 1, 113.32, i++, -1.646);
	AddWall(10, 2, 1, 732.51, 1, 113.34, i++, 1.461);
	//curva 3 (curvon)ext
	AddWall(10, 2, 1, 742.5, 1, 113.1, i++, 1.574);
	AddWall(10, 2, 1, 752.53, 1, 112.91, i++, 0.83);
	AddWall(10, 2, 1, 762.57, 1, 112.98, i++, -1.534);
	AddWall(10, 2, 1, 772.57, 1, 113.25, i++, -2.291);
	AddWall(10, 2, 1, 782.6, 1, 113.71, i++, -4.421);
	AddWall(10, 2, 1, 792.57, 1, 114.68, i++, -6.539);
	AddWall(10, 2, 1, 802.5, 1, 115.76, i++, -6.164);
	AddWall(10, 2, 1, 812.47, 1, 116.88, i++, -7.292);
	AddWall(10, 2, 1, 822.32, 1, 118.64, i++, -13.683);
	AddWall(10, 2, 1, 831.7, 1, 121.84, i++, -22.561);
	AddWall(10, 2, 1, 840.71, 1, 126.68, i++, -36.064);
	AddWall(10, 2, 1, 848.44, 1, 133.13, i++, -44.198);
	AddWall(10, 2, 1, 854.84, 1, 140.95, i++, -56.756);
	AddWall(10, 2, 1, 859.65, 1, 149.8, i++, -66.458);
	AddWall(10, 2, 1, 863.16, 1, 159.25, i++, -75.077);
	AddWall(10, 2, 1, 865, 1, 169.16, i++, -84.055);
	AddWall(10, 2, 1, 866, 1, 179.17, i++, -84.055);
	AddWall(10, 2, 1, 866.5, 1, 189.22, i++, -89.341);
	AddWall(10, 2, 1, 866.5, 1, 199.22, i++, -89.105);
	AddWall(10, 2, 1, 865.75, 1, 209.24, i++, -98.855);
	AddWall(10, 2, 1, 863.89, 1, 219.03, i++, -101.922);
	AddWall(10, 2, 1, 860.98, 1, 228.64, i++, -111.619);
	AddWall(10, 2, 1, 857.04, 1, 237.84, i++, -113.516);
	AddWall(10, 2, 1, 852.34, 1, 246.72, i++, -122.458);
	AddWall(10, 2, 1, 846.49, 1, 254.96, i++, 53.736);
	AddWall(10, 2, 1, 839.97, 1, 262.6, i++, 44.296);
	AddWall(10, 2, 1, 831.92, 1, 268.8, i++, 32.024);
	AddWall(10, 2, 1, 823.03, 1, 273.48, i++, 22.463);
	AddWall(10, 2, 1, 813.31, 1, 276.18, i++, 7.983);
	AddWall(10, 2, 1, 803.28, 1, 276.74, i++, -2.188);
	AddWall(10, 2, 1, 793.11, 1, 276.17, i++, -5.66);
	AddWall(10, 2, 1, 783.19, 1, 274.7, i++, -10.947);
	AddWall(10, 2, 1, 773.33, 1, 273, i++, -8.454);
	AddWall(10, 2, 1, 763.43, 1, 271.59, i++, -8.178);
	AddWall(10, 2, 1, 753.53, 1, 270.19, i++, -7.972);
	AddWall(10, 2, 1, 743.63, 1, 268.78, i++, -8.349);
	AddWall(10, 2, 1, 733.73, 1, 267.38, i++, -8.284);
	AddWall(10, 2, 1, 723.82, 1, 265.97, i++, -8.284);
	AddWall(10, 2, 1, 714.13, 1, 264.6, i++, -8.284);
	AddWall(10, 2, 1, 704.23, 1, 263.19, i++, -8.284);
	AddWall(10, 2, 1, 694.33, 1, 261.79, i++, -8.284);
	AddWall(10, 2, 1, 684.43, 1, 260.39, i++, -8.284);
	AddWall(10, 2, 1, 674.53, 1, 258.98, i++, -8.284);
	AddWall(10, 2, 1, 664.63, 1, 257.58, i++, -8.284);
	AddWall(10, 2, 1, 654.72, 1, 256.17, i++, -8.284);
	AddWall(10, 2, 1, 645.03, 1, 254.8, i++, -8.284);
	AddWall(10, 2, 1, 635.13, 1, 253.39, i++, -8.284);
	AddWall(10, 2, 1, 625.2, 1, 251.99, i++, -8.284);
	AddWall(10, 2, 1, 615.3, 1, 250.58, i++, -8.284);
	AddWall(10, 2, 1, 605.47, 1, 249.54, i++, -3.888);
	AddWall(10, 2, 1, 595.52, 1, 249.19, i++, -0.88);
	AddWall(10, 2, 1, 585.49, 1, 249.13, i++, -0.886);
	AddWall(10, 2, 1, 575.53, 1, 249.35, i++, 3.113);
	AddWall(10, 2, 1, 565.6, 1, 250.29, i++, 6.737);
	AddWall(10, 2, 1, 555.75, 1, 251.78, i++, 10.738);
	AddWall(10, 2, 1, 545.88, 1, 253.58, i++, 9.694);
	AddWall(10, 2, 1, 536.14, 1, 255.64, i++, 13.896);
	AddWall(10, 2, 1, 526.46, 1, 258.01, i++, 12.936);
	AddWall(10, 2, 1, 516.66, 1, 260.09, i++, 12.33);
	AddWall(10, 2, 1, 506.77, 1, 261.41, i++, 2.855);
	AddWall(10, 2, 1, 496.79, 1, 261.17, i++, -4.461);
	AddWall(10, 2, 1, 486.95, 1, 259.58, i++, -12.562);
	AddWall(10, 2, 1, 477.28, 1, 256.71, i++, -20.202);
	AddWall(10, 2, 1, 468.27, 1, 252.41, i++, -30.818);
	AddWall(10, 2, 1, 460.3, 1, 246.27, i++, -44.136);
	AddWall(10, 2, 1, 453.68, 1, 238.82, i++, -52.169);
	AddWall(10, 2, 1, 448, 1, 230.48, i++, -59.522);
	AddWall(10, 2, 1, 443.74, 1, 221.46, i++, -69.444);
	AddWall(10, 2, 1, 440.84, 1, 211.94, i++, -77.815);
	AddWall(10, 2, 1, 438.98, 1, 202.13, i++, -81.403);
	AddWall(10, 2, 1, 437.07, 1, 192.56, i++, -76.45);
	AddWall(10, 2, 1, 434.75, 1, 182.9, i++, -76.997);
	AddWall(10, 2, 1, 431.92, 1, 173.44, i++, -70.71);
	AddWall(10, 2, 1, 428.18, 1, 164.31, i++, -64.466);
	AddWall(10, 2, 1, 423.21, 1, 155.6, i++, -56.489);
	AddWall(10, 2, 1, 417.74, 1, 147.3, i++, -57.133);
	AddWall(10, 2, 1, 411.86, 1, 139.36, i++, -51.14);
	AddWall(10, 2, 1, 405.24, 1, 132.05, i++, -45.5);
	AddWall(10, 2, 1, 397.8, 1, 125.48, i++, -38.088);
	AddWall(10, 2, 1, 390.04, 1, 119.26, i++, -39.14);
	AddWall(10, 2, 1, 382.01, 1, 113.52, i++, -33.521);
	AddWall(10, 2, 1, 373.46, 1, 108.6, i++, -26.853);
	AddWall(10, 2, 1, 364.56, 1, 104.96, i++, -18.644);
	AddWall(10, 2, 1, 355.17, 1, 101.68, i++, -19.891);
	AddWall(10, 2, 1, 345.69, 1, 98.95, i++, -13.904);
	AddWall(10, 2, 1, 335.99, 1, 97.15, i++, -7.324);
	AddWall(10, 2, 1, 325.98, 1, 95.91, i++, -7.125);
	AddWall(10, 2, 1, 316.12, 1, 95.19, i++, -2.349);
	AddWall(10, 2, 1, 306.44, 1, 95.12, i++, 0);
	AddWall(10, 2, 1, 296.49, 1, 95.06, i++);
	AddWall(10, 2, 1, 286.56, 1, 95.06, i++);
	AddWall(10, 2, 1, 276.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 266.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 256.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 246.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 236.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 226.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 216.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 206.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 196.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 186.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 176.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 166.56, 1, 95.19, i++);
	AddWall(10, 2, 1, 157.01, 1, 95.44, i++, 2.949);
	AddWall(10, 2, 1, 148.04, 1, 98.3, i++, 31891);
	AddWall(10, 2, 1, 141.17, 1, 104.94, i++, 55.774);
	AddWall(10, 2, 1, 138.29, 1, 113.69, i++, 87.242);
	AddWall(10, 2, 1, 139.41, 1, 123.25, i++, -72.875);
	AddWall(10, 2, 1, 144.01, 1, 131.62, i++, -48.691);
	AddWall(10, 2, 1, 151.66, 1, 137.4, i++, -25.085);
	AddWall(10, 2, 1, 160.88, 1, 139.75, i++, -2.743);
	AddWall(10, 2, 1, 170.82, 1, 139.57, i++, 4.748);
	AddWall(10, 2, 1, 180.69, 1, 138.89, i++, 1.95);
	AddWall(10, 2, 1, 190.66, 1, 138.58, i++, 1.344);
	AddWall(10, 2, 1, 200.72, 1, 138.7, i++, -3.383);
	AddWall(10, 2, 1, 210.69, 1, 139.48, i++, -6.798);
	AddWall(10, 2, 1, 220.63, 1, 141.27, i++, -15.475);
	AddWall(10, 2, 1, 230.2, 1, 144.15, i++, -19.274);
	AddWall(10, 2, 1, 239.54, 1, 147.73, i++, -22.496);
	AddWall(10, 2, 1, 248.67, 1, 151.8, i++, -26.067);
	AddWall(10, 2, 1, 257.43, 1, 156.82, i++, -35.157);
	AddWall(10, 2, 1, 265.49, 1, 162.74, i++, -38.071);
	AddWall(10, 2, 1, 273.4, 1, 168.96, i++, -39.234);
	AddWall(10, 2, 1, 280.98, 1, 175.47, i++, -41.464);
	AddWall(10, 2, 1, 288.45, 1, 182.01, i++, -40.132);
	AddWall(10, 2, 1, 296.08, 1, 188.48, i++, -40.132);

	AddWall(10, 2, 1, 303.71, 1, 194.94, i++, -40.132);
	AddWall(10, 2, 1, 311.34, 1, 201.41, i++, -40.132);
	AddWall(10, 2, 1, 318.97, 1, 207.87, i++, -40.132);
	AddWall(10, 2, 1, 326.44, 1, 214.2, i++, -40.132);
	AddWall(10, 2, 1, 334.07, 1, 220.66, i++, -40.132);
	AddWall(10, 2, 1, 341.7, 1, 227.13, i++, -40.132);
	AddWall(10, 2, 1, 349.33, 1, 233.59, i++, -40.132);
	AddWall(10, 2, 1, 356.96, 1, 240.05, i++, -40.132);
	AddWall(10, 2, 1, 364.59, 1, 246.52, i++, -40.132);
	AddWall(10, 2, 1, 372.3, 1, 252.89, i++, -40.132);
	AddWall(10, 2, 1, 379.88, 1, 259.31, i++, -40.132);
	AddWall(10, 2, 1, 387.28, 1, 265.84, i++, -40.132);
	AddWall(10, 2, 1, 394.9, 1, 272.32, i++, -40.132);
	AddWall(10, 2, 1, 402.52, 1, 278.8, i++, -40.132);
	AddWall(10, 2, 1, 410.13, 1, 285.27, i++, -40.132);
	AddWall(10, 2, 1, 417.59, 1, 291.62, i++, -40.132);
	AddWall(10, 2, 1, 425.21, 1, 298.1, i++, -40.132);
	AddWall(10, 2, 1, 432.83, 1, 304.57, i++, -40.132);
	AddWall(10, 2, 1, 440.45, 1, 311.05, i++, -40.132);
	AddWall(10, 2, 1, 448.07, 1, 317.53, i++, -40.132);
	AddWall(10, 2, 1, 455.68, 1, 324.01, i++, -40.132);
	AddWall(10, 2, 1, 463.39, 1, 330.39, i++, -40.132);
	AddWall(10, 2, 1, 470.95, 1, 336.83, i++, -40.132);
	AddWall(10, 2, 1, 478.48, 1, 343.46, i++, -40.132);
	AddWall(10, 2, 1, 486.05, 1, 349.9, i++, -40.132);
	AddWall(10, 2, 1, 493.15, 1, 356.77, i++, -48.14);
	AddWall(10, 2, 1, 499.83, 1, 364.11, i++, -47.849);
	AddWall(10, 2, 1, 504.98, 1, 372.72, i++, -71.184);
	AddWall(10, 2, 1, 506.88, 1, 382.43, i++, -87.682);
	AddWall(10, 2, 1, 506.64, 1, 392.42, i++, -95.108);
	AddWall(10, 2, 1, 505.04, 1, 402.25, i++, -102.362);
	AddWall(10, 2, 1, 502.16, 1, 411.92, i++, -110.804);
	AddWall(10, 2, 1, 497.13, 1, 420.51, i++, 49.79);
	AddWall(10, 2, 1, 489.73, 1, 427.34, i++, 35.074);
	AddWall(10, 2, 1, 481.27, 1, 432.61, i++, 28.887);
	AddWall(10, 2, 1, 471.67, 1, 435.9, i++, 9.824);
	AddWall(10, 2, 1, 461.72, 1, 437.31, i++, 5.843);
	AddWall(10, 2, 1, 451.55, 1, 437.2, i++, -7.268);
	AddWall(10, 2, 1, 441.68, 1, 435.94, i++, -8.043);
	AddWall(10, 2, 1, 431.79, 1, 434.5, i++, -8.775);
	AddWall(10, 2, 1, 422.04, 1, 432.89, i++, -9.164);
	AddWall(10, 2, 1, 412.22, 1, 431.47, i++, -8.367);
	AddWall(10, 2, 1, 402.44, 1, 430.05, i++, -8.274);
	AddWall(10, 2, 1, 392.54, 1, 428.63, i++, -8.274);
	AddWall(10, 2, 1, 382.7, 1, 427.16, i++, -8.274);
	AddWall(10, 2, 1, 372.81, 1, 425.71, i++, -8.274);
	AddWall(10, 2, 1, 363.07, 1, 424.1, i++, -8.274);
	AddWall(10, 2, 1, 353.29, 1, 422.25, i++, -13.938);
	AddWall(10, 2, 1, 349.53, 1, 420.09, i++, -12.798);
	AddWall(10, 2, 1, 333.93, 1, 417.14, i++, -20.969);
	AddWall(10, 2, 1, 325.54, 1, 411.96, i++, -42.274);
	AddWall(10, 2, 1, 319.21, 1, 404.05, i++, -60.587);
	AddWall(10, 2, 1, 314.63, 1, 395.06, i++, -63.916);
	AddWall(10, 2, 1, 311.7, 1, 385.38, i++, -81.158);
	AddWall(10, 2, 1, 311.33, 1, 375.44, i++, -92.052);
	AddWall(10, 2, 1, 311.47, 1, 365.35, i++, -90.938);
	AddWall(10, 2, 1, 311.92, 1, 355.33, i++, -91.627);
	AddWall(10, 2, 1, 311.04, 1, 345.44, i++, -78.575);
	AddWall(10, 2, 1, 308.61, 1, 335.92, i++, -72.827);
	AddWall(10, 2, 1, 304.63, 1, 326.82, i++, -59.683);
	AddWall(10, 2, 1, 299.63, 1, 318.27, i++, -59.115);
	AddWall(10, 2, 1, 293.81, 1, 310.21, i++, -48.945);
	AddWall(10, 2, 1, 286.92, 1, 303.41, i++, -41.106);
	AddWall(10, 2, 1, 279.35, 1, 296.99, i++, -41.106);
	AddWall(10, 2, 1, 271.63, 1, 290.62, i++, -41.106);
	AddWall(10, 2, 1, 264, 1, 284.15, i++, -41.106);
	AddWall(10, 2, 1, 256.29, 1, 277.8, i++, -41.106);
	AddWall(10, 2, 1, 248.49, 1, 271.55, i++, -41.106);
	AddWall(10, 2, 1, 240.69, 1, 265.29, i++, -41.106);
	AddWall(10, 2, 1, 232.89, 1, 259.03, i++, -41.106);
	AddWall(10, 2, 1, 225.32, 1, 252.52, i++, -41.106);
	AddWall(10, 2, 1, 217.51, 1, 246.56, i++, -41.106);
	AddWall(10, 2, 1, 209.61, 1, 240.47, i++, -41.106);
	AddWall(10, 2, 1, 200.28, 1, 236.56, i++, -10.273);
	AddWall(10, 2, 1, 190.35, 1, 236.99, i++, 14.01);
	AddWall(10, 2, 1, 171.06, 1, 240.78, i++, 30.657);
	AddWall(10, 2, 1, 174.4, 1, 247.98, i++, 62.999);
	AddWall(10, 2, 1, 173.51, 1, 257.57, i++, -72.022);
	AddWall(10, 2, 1, 177.37, 1, 266.91, i++, -61.294);
	AddWall(10, 2, 1, 184.28, 1, 274.97, i++, -40.28);
	AddWall(10, 2, 1, 192.61, 1, 281.4, i++, -39.615);
	AddWall(10, 2, 1, 200.42, 1, 287.66, i++, -39.615);
	AddWall(10, 2, 1, 207.99, 1, 293.88, i++, -39.615);
	AddWall(10, 2, 1, 215.79, 1, 300.13, i++, -39.615);
	AddWall(10, 2, 1, 223.59, 306.39, i++, -39.615);
	AddWall(10, 2, 1, 231.39, 1, 312.65, i++, -39.615);
	AddWall(10, 2, 1, 239.1, 1, 319, i++, -39.615);
	AddWall(10, 2, 1, 246.73, 1, 325.46, i++, -39.615);
	AddWall(10, 2, 1, 254.01, 332.38, i++, -48.759);
	AddWall(10, 2, 1, 260.37, 1, 340.33, i++, -53.818);
	AddWall(10, 2, 1, 265.04, 1, 349.3, i++, -71.447);
	AddWall(10, 2, 1, 267.27, 1, 385.95, i++, -83.691);
	AddWall(10, 2, 1, 267.7, 1, 368.93, i++, -91.768);
	AddWall(10, 2, 1, 265.81, 1, 378.49, i++, -111.101);
	AddWall(10, 2, 1, 261.62, 1, 387.66, i++, -118.699);
	AddWall(10, 2, 1, 255.44, 1, 395.47, i++, -138.444);
	AddWall(10, 2, 1, 247.18, 1, 401.22, i++, -151.515);
	AddWall(10, 2, 1, 237.85, 1, 404.64, i++, 13.233);
	AddWall(10, 2, 1, 227.85, 1, 405.65, i++, -1);
	AddWall(10, 2, 1, 217.9, 1, 404.87, i++, -8.653);
	AddWall(10, 2, 1, 208.01, 1, 403.42, i++, -8.653);
	AddWall(10, 2, 1, 198.27, 1, 401.82, i++, -8.653);
	AddWall(10, 2, 1, 188.44, 1, 400.4, i++, -8.653);
	AddWall(10, 2, 1, 178.66, 1, 398.98, i++, -8.653);
	AddWall(10, 2, 1, 168.77, 1, 397.55, i++, -8.653);
	AddWall(10, 2, 1, 158.92, 396.08, i++, -8.653);
	AddWall(10, 2, 1, 149.03, 1, 394.64, i++, -8.653);
	AddWall(10, 2, 1, 139.29, 1, 393.03, i++, -8.653);
	AddWall(10, 2, 1, 129.27, 1, 391.06, i++, -8.653);
	AddWall(10, 2, 1, 119.57, 1, 389.2, i++, -8.653);
	AddWall(10, 2, 1, 109.71, 1, 387.34, i++, -8.653);
	AddWall(10, 2, 1, 99.98, 1, 385.44, i++, -8.653);
	AddWall(10, 2, 1, 90.16, 1, 383.56, i++, -8.653);
	AddWall(10, 2, 1, 80.5, 1, 381.53, i++, -8.653);
	AddWall(10, 2, 1, 70.87, 1, 378.66, i++, -20.874);
	AddWall(10, 2, 1, 61.76, 1, 374.56, i++, -26.869);
	AddWall(10, 2, 1, 53.08, 1, 369.52, i++, -33.402);
	AddWall(10, 2, 1, 45.19, 1, 363.52, i++, -41.597);
	AddWall(10, 2, 1, 38.51, 1, 356.05, i++, -57.418);
	AddWall(10, 2, 1, 34.05, 1, 347.09, i++, -68.124);
	AddWall(10, 2, 1, 31.25, 1, 337.44, i++, -77.125);
	AddWall(10, 2, 1, 29.92, 1, 327.62, i++, -84.778);
	AddWall(10, 2, 1, 29.82, 1, 317.67, i++, 85.33);
	AddWall(10, 2, 1, 31.74, 1, 307.85, i++, 72.61);
	AddWall(10, 2, 1, 35.3, 1, 298.46, i++, 64.699);
	AddWall(10, 2, 1, 38.76, 1, 289.28, i++, 75.443);
	AddWall(10, 2, 1, 41.25, 1, 279.35, i++, 75.899);
	AddWall(10, 2, 1, 42.93, 1, 269.7, i++, 84.844);
	AddWall(10, 2, 1, 43.83, 1, 259.65, i++, 84.377);
	AddWall(10, 2, 1, 44.12, 1, 249.85, i++, 93.786);
	AddWall(10, 2, 1, 43.25, 1, 239.65, i++, 95.54);
	AddWall(10, 2, 1, 41.7, 1, 229.97, i++, -75.714);
	AddWall(10, 2, 1, 39.15, 1, 220.43, i++, -78.708);
	AddWall(10, 2, 1, 36.76, 1, 210.93, i++, -70.799);
	AddWall(10, 2, 1, 32.77, 1, 201.55, i++, -63.997);
	AddWall(10, 2, 1, 27.48, 1, 193.46, i++, -48.519);
	AddWall(10, 2, 1, 20.71, 1, 186.34, i++, -44.208);
	AddWall(10, 2, 1, 13.61, 1, 179.6, i++, -44.208);
	//interns 
	AddWall(10, 2, 1, 107.8, 1, 28.19, i++, 7.326);
	AddWall(10, 2, 1, 117.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 127.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 137.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 147.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 157.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 167.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 177.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 187.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 197.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 207.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 207.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 217.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 227.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 237.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 247.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 257.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 267.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 277.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 287.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 297.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 307.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 317.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 327.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 337.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 347.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 357.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 367.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 377.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 387.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 397.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 407.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 417.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 427.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 437.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 446.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 456.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 466.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 476.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 486.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 496.78, 1, 27.64, i++);
	AddWall(10, 2, 1, 506.53, 1, 27.9, i++, -3.073);
	AddWall(10, 2, 1, 516.25, 1, 28.63, i++, -6.299);
	AddWall(10, 2, 1, 526, 1, 29.58, i++, -6.03);
	AddWall(10, 2, 1, 535.95, 1, 30.55, i++, -6.015);
	AddWall(10, 2, 1, 545.9, 1, 31.53, i++, -5.918);
	AddWall(10, 2, 1, 555.86, 1, 32.5, i++, -6.608);
	AddWall(10, 2, 1, 564.59, 1, 36.61, i++, -48.14);
	AddWall(10, 2, 1, 566.9, 1, 45.6, i++, 75.91);
	AddWall(10, 2, 1, 562.17, 1, 53.55, i++, 46.532);
	AddWall(10, 2, 1, 553.89, 1, 59.1, i++, 19.866);
	AddWall(10, 2, 1, 545.08, 62.61, i++, 20.123);
	AddWall(10, 2, 1, 535.76, 1, 66.34, i++, 21.674);
	AddWall(10, 2, 1, 526.95, 1, 70.73, i++, 30.964);
	AddWall(10, 2, 1, 519.33, 1, 76.61, i++, 39.514);
	AddWall(10, 2, 1, 512.1, 1, 83.5, i++, 45.31);
	AddWall(10, 2, 1, 506.13, 1, 91.04, i++, 54.648);
	AddWall(10, 2, 1, 501.44, 1, 98.94, i++, 63.979);
	AddWall(10, 2, 1, 498.27, 1, 108.02, i++, 72.745);
	AddWall(10, 2, 1, 495.61, 1, 117.14, i++, 74.105);
	AddWall(10, 2, 1, 493.99, 1, 126.62, i++, 82.521);
	AddWall(10, 2, 1, 492.464, 1, 136.075, i++, 79.746);
	AddWall(10, 2, 1, 491.09, 1, 146.07, i++, 81.158);
	AddWall(10, 2, 1, 489.38, 1, 156.04, i++, 79.453);
	AddWall(10, 2, 1, 488, 1, 166.04, i++, 80.74);
	AddWall(10, 2, 1, 486.21, 1, 176.07, i++, 80.74);
	AddWall(10, 2, 1, 484.83, 1, 186.07, i++, 82.34);
	AddWall(10, 2, 1, 483.12, 1, 196.03, i++, 79.089);
	AddWall(10, 2, 1, 481.74, 1, 206.03, i++, 81.488);
	AddWall(10, 2, 1, 478.6, 1, 215.73, i++, 62.241);
	AddWall(10, 2, 1, 472.9, 1, 216.25, i++, -43.025);
	AddWall(10, 2, 1, 467.09, 1, 208.21, i++, -66.329);
	AddWall(10, 2, 1, 464.01, 1, 198.36, i++, -77.569);
	AddWall(10, 2, 1, 462.24, 1, 188.53, i++, -81.521);
	AddWall(10, 2, 1, 460.24, 1, 178.99, i++, -75.719);
	AddWall(10, 2, 1, 457.93, 1, 169.32, i++, -76.752);
	AddWall(10, 2, 1, 455.1, 1, 159.87, i++, -71.346);
	AddWall(10, 2, 1, 451.36, 1, 150.74, i++, -65.688);
	AddWall(10, 2, 1, 446.39, 1, 142.02, i++, -56.179);
	AddWall(10, 2, 1, 440.92, 1, 133.72, i++, -57.08);
	AddWall(10, 2, 1, 435.04, 1, 125.79, i++, -50.45);
	AddWall(10, 2, 1, 428.42, 1, 118.48, i++, -45.458);
	AddWall(10, 2, 1, 421.13, 1, 111.67, i++, -41.646);
	AddWall(10, 2, 1, 413.82, 1, 105.08, i++, -43.716);
	AddWall(10, 2, 1, 406.33, 1, 98.65, i++, -37.84);
	AddWall(10, 2, 1, 398.27, 1, 93.11, i++, -32.469);
	AddWall(10, 2, 1, 389.72, 1, 88.7, i++, -24.052);
	AddWall(10, 2, 1, 380.66, 1, 84.59, i++, -24.669);
	AddWall(10, 2, 1, 371.44, 1, 80.88, i++, -17.953);
	AddWall(10, 2, 1, 361.94, 1, 77.88, i++, -16.632);
	AddWall(10, 2, 1, 352.44, 1, 75.3, i++, -13.216);
	AddWall(10, 2, 1, 342.63, 1, 73.25, i++, -11.31);
	AddWall(10, 2, 1, 333.02, 1, 71.63, i++, -5.852);
	AddWall(10, 2, 1, 323.1, 1, 70.74, i++, -4.554);
	AddWall(10, 2, 1, 313.36, 1, 70.12, i++, -3.599);
	AddWall(10, 2, 1, 303.4, 1, 69.84, i++, -0.977);
	AddWall(10, 2, 1, 293.38, 1, 69.9, i++);
	AddWall(10, 2, 1, 283.38, 1, 70.22, i++, 1.757);
	AddWall(10, 2, 1, 273.38, 1, 70.42, i++, 1.757);
	AddWall(10, 2, 1, 263.39, 1, 70.62, i++, 1.757);
	AddWall(10, 2, 1, 253.39, 1, 70.81, i++, 1.757);
	AddWall(10, 2, 1, 243.39, 1, 71.01, i++, 1.757);
	AddWall(10, 2, 1, 233.39, 1, 71.21, i++, 1.757);
	AddWall(10, 2, 1, 223.6, 1, 71.4, i++, 1.757);
	AddWall(10, 2, 1, 213.6, 1, 71.6, i++, 1.757);
	AddWall(10, 2, 1, 203.59, 1, 71.65, i++, 1.757);
	AddWall(10, 2, 1, 193.59, 1, 71.76, i++, 1.757);
	AddWall(10, 2, 1, 183.59, 1, 71.87, i++, 1.757);
	AddWall(10, 2, 1, 173.58, 1, 72.14, i++, 1.757);
	AddWall(10, 2, 1, 163.58, 1, 72.25, i++, 1.757);
	AddWall(10, 2, 1, 153.58, 1, 72.64, i++, 1.757);
	AddWall(10, 2, 1, 143.58, 1, 72.75, i++, 1.757);
	AddWall(10, 2, 1, 133.59, 1, 74.04, i++, 15.424);
	AddWall(10, 2, 1, 124.31, 1, 77.88, i++, 29.942);
	AddWall(10, 2, 1, 116.58, 1, 83.5, i++, 43.388);
	AddWall(10, 2, 1, 110.37, 1, 91.38, i++, 59.514);
	AddWall(10, 2, 1, 106.06, 1, 99.63, i++, 64.798);
	AddWall(10, 2, 1, 103.19, 1, 109.26, i++, 81.745);
	AddWall(10, 2, 1, 102.68, 1, 118.96, i++, 90);
	AddWall(10, 2, 1, 104.02, 1, 128.91, i++, -74.055);
	AddWall(10, 2, 1, 107.46, 1, 138.46, i++, -68.057);
	AddWall(10, 2, 1, 112.38, 1, 147.21, i++, -53.111);
	AddWall(10, 2, 1, 118.67, 1, 154.6, i++, -45.397);
	AddWall(10, 2, 1, 126.61, 1, 160.76, i++, -30.442);
	AddWall(10, 2, 1, 135.24, 164.88, i++, -18.067);
	AddWall(10, 2, 1, 145.09, 1, 166.8, i++, -2.8);
	AddWall(10, 2, 1, 155.14, 1, 166.72, i++, 5.172);
	AddWall(10, 2, 1, 165, 1, 166.05, i++, 2.268);
	AddWall(10, 2, 1, 174.98, 1, 165.74, i++, 1.081);
	AddWall(10, 2, 1, 185.01, 1, 165.37, i++, 1.081);
	AddWall(10, 2, 1, 195, 1, 165.17, i++, -1.175);
	AddWall(10, 2, 1, 205.07, 1, 165.98, i++, -9.34);
	AddWall(10, 2, 1, 214.84, 1, 167.91, i++, -12.715);
	AddWall(10, 2, 1, 224.08, 1, 170.71, i++, 21.43);
	AddWall(10, 2, 1, 233.21, 1, 174.78, i++, -26.046);
	AddWall(10, 2, 1, 241.98, 1, 179, i++, -34.854);
	AddWall(10, 2, 1, 250.03, 1, 185.72, i++, -39.149);
	AddWall(10, 2, 1, 257.86, 1, 191.87, i++, -38.077);
	AddWall(10, 2, 1, 265.51, 1, 198.3, i++, -41.188);
	AddWall(10, 2, 1, 273.04, 1, 204.76, i++, -41.188);
	AddWall(10, 2, 1, 280.74, 1, 211.14, i++, -41.188);
	AddWall(10, 2, 1, 288.44, 1, 217.53, i++, -41.188);
	AddWall(10, 2, 1, 296.14, 1, 223.91, i++, -41.188);
	AddWall(10, 2, 1, 303.84, 1, 230.29, i++, -41.188);
	AddWall(10, 2, 1, 311.38, 1, 236.54, i++, -41.188);
	AddWall(10, 2, 1, 319.07, 1, 242.92, i++, -41.188);
	AddWall(10, 2, 1, 326.77, 1, 249.3, i++, -41.188);
	AddWall(10, 2, 1, 334.47, 1, 255.69, i++, -41.188);
	AddWall(10, 2, 1, 342.17, 1, 262.07, i++, -41.188);
	AddWall(10, 2, 1, 349.87, 1, 268.45, i++, -41.188);

	return ret;
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	//Plane p(0, 1, 0, 0);
	//p.Render();
	Floor.Render();

	for (int i = 0; i < wall.Count(); i++) {
		wall[i].Render();
	}
	for (int i = 0; i < powerups.Count(); i++) {
		if (powerups[i].invisible != true) {
			powerups[i].Render();
			powerups[i].SetRotation(x, { 0,90,0 });
		}
	}

	if (x < 360) {
		x++;
	}else {
		x = 0;
	}
	
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	//App->player->fuel += 0.02;
	if (body1 == sensor[0]) {	
		if (sensor[1]->checkpoint == true) {
			lap = actual;
			LOG("LAP TIME: %i SECONDS", lap.Read()/1000);
			sensor[1]->checkpoint = false;
		}
		actual.Start();
	}
	else if (body1 == sensor[1]) {
		sensor[1]->checkpoint = true;
	}
	else if (body1->ispowerup == true) {
		if (powerups[body1->id].invisible != true) {
			LOG("POWER UP");
			powerups[body1->id].invisible = true;
		}
	}
}

void ModuleSceneIntro::AddWall(uint size_x, uint size_y, uint size_z, float pos_x, float pos_y, float pos_z, int tag, float angle) {

	Color color = Black;
	if (tag % 2 == 0) {
		color = Red;
	}
	else {
		color = Black;
	}
	Cube w1;
	w1.size.Set(size_x, size_y, size_z);
	w1.SetPos(pos_x, pos_y, pos_z);
	w1.color = color;
	w1.SetRotation(angle, { 0,90,0 });
	wall.PushBack(w1);
	App->physics->AddBody(wall[wall.Count() - 1], 0);
}

void ModuleSceneIntro::AddPowerUp(uint size_x, uint size_y, uint size_z, float pos_x, float pos_y, float pos_z, uint id) {

	Cube w1;
	w1.size.Set(size_x, size_y, size_z);
	w1.SetPos(pos_x, pos_y, pos_z);
	w1.color = Blue;
	powerups.PushBack(w1);
	pu_body[id]=App->physics->AddBody(w1, 0.0f);
	pu_body[id]->SetAsPowerup(true,id);
	pu_body[id]->collision_listeners.add(this);
}

void ModuleSceneIntro::AddSens(uint size_x, uint size_y, uint size_z, float pos_x, float pos_y, float pos_z, uint id) {

	sens[id].size = vec3(size_x, size_y, size_z);
	sens[id].SetPos(pos_x, pos_y, pos_z);
	sensor[id] = App->physics->AddBody(sens[id], 0.0f);
	sensor[id]->SetAsSensor(true);
	sensor[id]->collision_listeners.add(this);
}	
