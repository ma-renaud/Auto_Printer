#include <QApplication>
#include "AutoPrinter.h"
#include <iostream>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  std::string mystr;
  std::cout << "Folder to check: ";
  getline (std::cin, mystr);

  AutoPrinter printer(QString::fromStdString(mystr));
  printer.checkForPdf ();

  return 0;
}
