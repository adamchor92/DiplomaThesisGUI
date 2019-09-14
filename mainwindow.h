#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "QtSerialPort/QSerialPort"
#include "uart_frame_struct.h"
#include "module.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initPortList();
    void fullFrameReceived(QByteArray & receivedBytes);
    void updateGUI();
    void InitConnectionModule(int module);
    void openPort(QString portName);
    void sendFrame();
    void startLinearGraph();
    void startSineGraph();

private slots:
    void on_pushButton_Open_clicked();
    void on_pushButton_Send_pressed();
    void on_pushButton_InitConnectionModule1_clicked();
    void on_pushButton_InitConnectionModule2_clicked();
    void on_pushButton_StartLinear_clicked();
    void on_pushButton_StartSine_clicked();

    void serialDataReceived();

    void on_pushButton_Stop_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort* m_serial;
    Module* m_module1;
    Module* m_module2;

    UARTFrameStruct_t m_s_UARTFrame;

    bool m_stopPressed;
};

#endif // MAINWINDOW_H
