// Copyright (c) 2017-2018 The CALIBUR developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZCBRCONTROLDIALOG_H
#define ZCBRCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zcbr/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZCBRControlDialog;
}

class CZCBRControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZCBRControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZCBRControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZCBRControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZCBRControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZCBRControlDialog(QWidget *parent);
    ~ZCBRControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZCBRControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZCBRControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZCBRCONTROLDIALOG_H
