#pragma once

#include <QWidget>
#include "ui_mainwindow.h"

class TableView
{
public:
    TableView(Ui::MainWindow* pUiHandle);

    static TableView & getSingleton()
    {
        static TableView singleton;
        return singleton;
    }

    void initPacketDisplay();
    void updatePacket(uint8_t UART_MessageToTransmit[], bool isReceivedPacket);
    void clearPacketDisplay();

private:
    TableView();
    TableView( const TableView & );

    Ui::MainWindow* m_pUiHandle;
    QTableWidget* m_pTableWidget;

    const int PACKET_SIZE = 20;
};
