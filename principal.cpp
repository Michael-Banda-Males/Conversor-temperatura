#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    // Conectar el dial de Centigrados con el slot de ESTA clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
           this,SLOT(cent2fahr_kelv(int)));
    // Conectar el dial de Fahrenheith con el slot de ESTA clase
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
           this,SLOT(fahr2cent_kelv(int)));
    // Conectar el dial de Kelvin con el slot de ESTA clase
    connect(ui->inKelv, SIGNAL(valueChanged(int)),
           this,SLOT(kelv2cent_fahr(int)));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fahr_kelv(int cent)
{
    if (ui->inCent->hasFocus()){
        int fahr = (cent * 9.0/5) + 32;
        int kelv= cent + 273.15;
        ui->inKelv->setValue(kelv);
        ui->inFahr->setValue(fahr);
    }
}

void Principal::fahr2cent_kelv(int i)
{
    if (ui->inFahr->hasFocus()){
        int c = (i - 32) * 5.0/9;
        int kelv = c +273.15;
        ui->inCent->setValue(c);
        ui->inKelv->setValue(kelv);
    }
}

void Principal::kelv2cent_fahr(int k)
{
    if (ui->inKelv->hasFocus()){
        int c = k - 273.15;
        int f = (c*9/5) + 32;
        ui->inCent->setValue(c);
        ui->inFahr->setValue(f);
    }
}



