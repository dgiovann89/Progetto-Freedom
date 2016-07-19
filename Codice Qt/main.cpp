#include<iostream>
#include <QApplication>
#include<finestraprincipale.h>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  FinestraPrincipale window;
  window.show();

  return app.exec();
}
