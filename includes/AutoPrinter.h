#ifndef AUTOPRINTER_AUTOPRINTER_H
#define AUTOPRINTER_AUTOPRINTER_H

#include <string>

class AutoPrinter {
public:
  AutoPrinter() = default;
  ~AutoPrinter () = default;

  bool PrintPDFs(std::string pdfFileName);

};

#endif //AUTOPRINTER_AUTOPRINTER_H
