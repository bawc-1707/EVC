#include "nfcworker.h"
#include <QDebug>

NFCWorker::NFCWorker(nfc_device *device, QObject *parent)
    : QObject(parent), pnd(device), running(true)
{
    nfc_init(&context);
    if(context == nullptr){
        qDebug() << "Khong the khoi tao nfc" << Qt::endl;
        return;
    }
    pnd = nfc_open(context, nullptr);
    if(pnd == nullptr){
        qDebug() << "Khong the mo thiet bi nfc" << Qt::endl;
        return;
    }
    if(nfc_initiator_init(pnd) < 0){
        nfc_close(pnd);
        nfc_exit(context);
        qDebug() << "Khong the khoi tao thiet bi nfc" << Qt::endl;
        return;
    }
}


void NFCWorker::checkNfc() {
    QString uid;
    nfc_target nt;

    while (running) {
        int res = nfc_initiator_poll_target(pnd, nmModulations, szModulations, uiPollNr, uiPeriod, &nt);

        if (res > 0) {
            uid.clear();

            for (int i = 0; i < nt.nti.nai.szUidLen; i++) {
                uid += QString::number(nt.nti.nai.abtUid[i], 16).toUpper().rightJustified(2, '0');
            }
            emit nfcDetected(uid);
            break;
        }
    }
}

void NFCWorker::stop() {
    running = false;
}

void NFCWorker::start(){
    running = true;
}
