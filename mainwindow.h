#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminneurona.h"
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_widget_customContextMenuRequested(const QPoint &pos);

    void on_btnAgregarInicio_clicked();

    void on_btnAgregarFinal_clicked();

    void on_btnVerNeuronas_clicked();

    void on_GuardarN_clicked();

    void on_RecuperarN_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AdminNeurona administrador;
    QPlainTextEdit *neuronasTextEdit;
};
#endif // MAINWINDOW_H
