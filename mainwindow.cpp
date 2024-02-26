#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "adminneurona.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_widget_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_btnAgregarInicio_clicked()
{
    bool ok;

    QString idTexto = ui->campoId->text();
    int id = idTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString voltajeTexto = ui->campoVoltaje->text();
    float voltaje = voltajeTexto.toFloat(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }


    QString posXTexto = ui->campoPosX->text();
    int posX = posXTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString posYTexto = ui->campoPosY->text();
    int posY = posYTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString redTexto = ui->campoRed->text();
    int red = redTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString greenTexto = ui->campoGreen->text();
    int green = greenTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString blueTexto = ui->campoBlue->text();
    int blue = blueTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    administrador.agregarInicio(Neurona(id, voltaje, posX, posY, red, green, blue));
    qDebug() << "Nueva neurona agregada";

    ui->neuronasInfo->setPlainText("Neurona agregada al inicio");
}



void MainWindow::on_btnAgregarFinal_clicked()
{
    bool ok;

    QString idTexto = ui->campoId->text();
    int id = idTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString voltajeTexto = ui->campoVoltaje->text();
    float voltaje = voltajeTexto.toFloat(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }


    QString posXTexto = ui->campoPosX->text();
    int posX = posXTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString posYTexto = ui->campoPosY->text();
    int posY = posYTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString redTexto = ui->campoRed->text();
    int red = redTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString greenTexto = ui->campoGreen->text();
    int green = greenTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString blueTexto = ui->campoBlue->text();
    int blue = blueTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    administrador.agregarFinal(Neurona(id, voltaje, posX, posY, red, green, blue));
    qDebug() << "Nueva neurona agregada";

    ui->neuronasInfo->setPlainText("Neurona agregada al final");
}


void MainWindow::on_btnVerNeuronas_clicked()
{
    QString informacionNeuronas = administrador.obtenerInformacionNeuronas();
    ui->neuronasInfo->setPlainText(informacionNeuronas);
}


void MainWindow::on_GuardarN_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar Neuronas"), "", tr("Archivos de Texto (*.txt)"));
    if (!fileName.isEmpty()) {
        // Llamar al método de la clase AdminNeurona para guardar las neuronas en el archivo
        administrador.guardarNeuronasEnArchivo(fileName);
    }
}


void MainWindow::on_RecuperarN_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Recuperar Neuronas", "", "Archivos de Texto (*.txt);;Todos los Archivos (*.*)");
    if (!filePath.isEmpty()) {
        administrador.recuperarNeuronasDesdeArchivo(filePath);
    }
}

