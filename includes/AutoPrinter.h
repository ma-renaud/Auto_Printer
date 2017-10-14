#ifndef AUTOPRINTER_AUTOPRINTER_H
#define AUTOPRINTER_AUTOPRINTER_H

#include <memory>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrinterInfo>

class AutoPrinter {
 public:
  explicit AutoPrinter(QString path);
  ~AutoPrinter() = default;

  void checkForPdf();
  void printPdf(QString path);

 private:
  QString dirToMonitor;
  std::unique_ptr<QPrinter> printer;
};

#endif //AUTOPRINTER_AUTOPRINTER_H
