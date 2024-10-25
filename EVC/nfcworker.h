#ifndef NFCWORKER_H
#define NFCWORKER_H

#include <QObject>
#include <nfc/nfc.h>
#include <nfc/nfc-types.h>

class NFCWorker : public QObject {
    Q_OBJECT
public:
    explicit NFCWorker(nfc_device *device, QObject *parent = nullptr);

public slots:
    void checkNfc();
    void stop();
    void start();

signals:
    void nfcDetected(const QString &uid);

private:
    bool running;
    nfc_device *pnd;
    nfc_context *context;
    const uint8_t uiPollNr = 1;
    const uint8_t uiPeriod = 1;
    const nfc_modulation nmModulations[6] = {
        { .nmt = NMT_ISO14443A, .nbr = NBR_106 },
        { .nmt = NMT_ISO14443B, .nbr = NBR_106 },
        { .nmt = NMT_FELICA, .nbr = NBR_212 },
        { .nmt = NMT_FELICA, .nbr = NBR_424 },
        { .nmt = NMT_JEWEL, .nbr = NBR_106 },
        { .nmt = NMT_ISO14443BICLASS, .nbr = NBR_106 },
    };
    const size_t szModulations = sizeof(nmModulations) / sizeof(nmModulations[0]);
};

#endif // NFCWORKER_H
