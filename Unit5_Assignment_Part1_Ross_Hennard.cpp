//for some reason adding the name, purpose of code etc stuff at the top of this file completely broke it and caused a makefile error i didn't know how to fix so thats no there for that reason
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>
using namespace std;
using namespace std;

double getNetPay(double, double, string, int);

int main() {
  locale loc;

  string str1 = "TCC-TR IS COOL";

  for (int i = 0; i < str1.length(); i++) {
    cout << tolower(str1[i], loc);
  }

  cout << fixed << setprecision(2);
  cout << getNetPay(47.0, 505.75, "Ross", 1) << endl;
  cout << getNetPay(45.0, 55.25, "Melvin", 1) << endl;
  cout << getNetPay(15.0, 65.25, "Susan", 2) << endl;
  cout << getNetPay(41.0, 14.75, "Mika", 1) << endl;
  cout << getNetPay(25.0, 15.0, "Eldridge", 2) << endl;
  cout << getNetPay(55.0, 203.50, "Freedom", 1) << endl;
  cout << getNetPay(32.5, 100.25, "Tyson", 1) << endl;
  return 0;
}

double getNetPay(double hours, double rate, string name, int employmentStatus) {

  double netPay = 0.0, grossPay = 0.0, taxableWages = 0.0;
  double ss = 0.062, med = 0.0145, sSwages = 0.0, medWages = 0.0;
  double FIT = 0.0, fitTax = 0.0, dental = 0.0, retirement = 0.0;
  double clockHours = 40.0, overtimeRate = 2.0, overTimeIfAny = 0.0;
  locale loc;
  string status = "";
  string reset = "\x1b[0m";
  string color = "\x1b[" + to_string(32) + ";4m";
  string color2 = "\x1b[" + to_string(34) + ";1m";

  cout << color << endl;
  for (int i = 0; i < name.length(); i++) {
    cout << toupper(name[i], loc);
  }
  cout << reset << endl;
  cout << endl;

  status = (employmentStatus == 1) ? "Fulltime" : "Parttime";
  cout << "\tStatus: " << status << endl;
  cout << "\tHours Worked: " << hours << " Rate: $" << rate << endl;

  overTimeIfAny = ((hours - clockHours) > 0.0) ? (hours - clockHours) : 0.0;
  if (employmentStatus == 1) {
    cout << "\tOvertime Hours: " << overTimeIfAny << endl;
  }

  FIT = (rate < 15.0) ? 0.12 : 0.15;
  cout << "\tFIT Rate: " << FIT << endl;
  dental = (employmentStatus == 1) ? 17.00 : 0.00;
  retirement = (employmentStatus == 1) ? 77.00 : 0.00;

  grossPay =
      (hours <= clockHours)
          ? (hours * rate)
          : ((clockHours * rate) + ((overTimeIfAny) * (overtimeRate * rate)));

  cout << "Gross Pay: $" << grossPay;
  taxableWages = grossPay - (dental + retirement);
  fitTax = taxableWages * FIT;

  sSwages = grossPay * ss;
  medWages = grossPay * med;

  cout << "\n\tDEDUCTIONS (preTax):" << reset << endl;
  cout << "\tDental Deduction: $" << dental << "\n\tRet. Deduction: $"
       << retirement << endl;
  cout << "Taxable Wages (for FIT): $" << taxableWages << endl;
  cout << "\tDEDUCTIONS:" << reset << endl;
  cout << "\tFIT Tax Amount: $" << fitTax << endl;

  cout << "\tSSDed = $" << sSwages << " MedDed = $" << medWages << endl;

  netPay = grossPay - (dental + retirement + fitTax + sSwages + medWages);

  cout << "NET PAY for " << color << name << " "
       << "$";
  return netPay;
}