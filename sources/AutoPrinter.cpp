#include "AutoPrinter.h"
#include <QPainter>
#include <QDir>
#include <poppler-qt5.h>

AutoPrinter::AutoPrinter(QString path) {
  dirToMonitor = std::move(path);
  QPrinterInfo selectedPrinter = QPrinterInfo::defaultPrinter();
  printer = std::make_unique<QPrinter>(selectedPrinter);
  printer->setPaperSize(QPrinter::Letter);
  printer->setFullPage(true);
  printer->setResolution(600);
  printer->setOrientation(QPrinter::Portrait);
}

void AutoPrinter::checkForPdf() {
  QDir folder(dirToMonitor);
  folder.setNameFilters(QStringList() << "*.pdf");
  QStringList fileList = folder.entryList();

  for (const auto &file: fileList) {
    printPdf(dirToMonitor + "/" + file);
  }
}

void AutoPrinter::printPdf(QString path) {
  QPainter painter(printer.get());

  Poppler::Document *document = Poppler::Document::load(path);

  if (document) {
    int pageCount = document->numPages();
    for (int i = 0; i < pageCount; i++) {
      QImage image = document->page(i)->renderToImage(printer->resolution(),
                                                      printer->resolution(),
                                                      -1,
                                                      -1,
                                                      printer->pageRect().width(),
                                                      printer->pageRect().height());
      painter.drawImage(QPoint(0, 0), image);
      if (i < pageCount - 1)
        printer->newPage();
    }
  }

  painter.end();
}
