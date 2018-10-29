/********************************************************************************
** Form generated from reading UI file 'SettingDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDLG_H
#define UI_SETTINGDLG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QRadioButton *rbCm;
    QRadioButton *rbInch;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *dsp1;
    QCheckBox *chShowGrid;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblLanguage;
    QComboBox *cmbLanguage;
    QCheckBox *chkUpdates;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *SettingDlg)
    {
        if (SettingDlg->objectName().isEmpty())
            SettingDlg->setObjectName(QStringLiteral("SettingDlg"));
        SettingDlg->resize(368, 249);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingDlg->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(SettingDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(SettingDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        rbCm = new QRadioButton(groupBox);
        rbCm->setObjectName(QStringLiteral("rbCm"));
        rbCm->setEnabled(true);
        rbCm->setChecked(true);

        verticalLayout_2->addWidget(rbCm);

        rbInch = new QRadioButton(groupBox);
        rbInch->setObjectName(QStringLiteral("rbInch"));
        rbInch->setEnabled(true);

        verticalLayout_2->addWidget(rbInch);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        dsp1 = new QDoubleSpinBox(groupBox);
        dsp1->setObjectName(QStringLiteral("dsp1"));
        dsp1->setMinimum(0.5);
        dsp1->setSingleStep(0.1);

        horizontalLayout_2->addWidget(dsp1);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        chShowGrid = new QCheckBox(groupBox);
        chShowGrid->setObjectName(QStringLiteral("chShowGrid"));

        horizontalLayout_3->addWidget(chShowGrid);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SettingDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lblLanguage = new QLabel(groupBox_2);
        lblLanguage->setObjectName(QStringLiteral("lblLanguage"));

        horizontalLayout_4->addWidget(lblLanguage);

        cmbLanguage = new QComboBox(groupBox_2);
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->setObjectName(QStringLiteral("cmbLanguage"));

        horizontalLayout_4->addWidget(cmbLanguage);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox_2);

        chkUpdates = new QCheckBox(SettingDlg);
        chkUpdates->setObjectName(QStringLiteral("chkUpdates"));

        verticalLayout->addWidget(chkUpdates);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(SettingDlg);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(SettingDlg);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SettingDlg);
        QObject::connect(btnCancel, SIGNAL(clicked()), SettingDlg, SLOT(reject()));
        QObject::connect(btnSave, SIGNAL(clicked()), SettingDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(SettingDlg);
    } // setupUi

    void retranslateUi(QDialog *SettingDlg)
    {
        SettingDlg->setWindowTitle(QApplication::translate("SettingDlg", "Settings", nullptr));
        groupBox->setTitle(QApplication::translate("SettingDlg", "Grid", nullptr));
        label_2->setText(QApplication::translate("SettingDlg", "Measurement's unit", nullptr));
        rbCm->setText(QApplication::translate("SettingDlg", "Cm", nullptr));
        rbInch->setText(QApplication::translate("SettingDlg", "Inch", nullptr));
        label->setText(QApplication::translate("SettingDlg", "Grid's step", nullptr));
        chShowGrid->setText(QApplication::translate("SettingDlg", "Show grid", nullptr));
        groupBox_2->setTitle(QApplication::translate("SettingDlg", "Internationalization", nullptr));
        lblLanguage->setText(QApplication::translate("SettingDlg", "Language:", nullptr));
        cmbLanguage->setItemText(0, QApplication::translate("SettingDlg", "System Default", nullptr));
        cmbLanguage->setItemText(1, QApplication::translate("SettingDlg", "Arabic \330\271\330\261\330\250\331\212", nullptr));
        cmbLanguage->setItemText(2, QApplication::translate("SettingDlg", "American English", nullptr));
        cmbLanguage->setItemText(3, QApplication::translate("SettingDlg", "Chinese", nullptr));
        cmbLanguage->setItemText(4, QApplication::translate("SettingDlg", "Dutch", nullptr));
        cmbLanguage->setItemText(5, QApplication::translate("SettingDlg", "French", nullptr));
        cmbLanguage->setItemText(6, QApplication::translate("SettingDlg", "Georgian \341\203\245\341\203\220\341\203\240\341\203\227\341\203\243\341\203\232\341\203\230", nullptr));
        cmbLanguage->setItemText(7, QApplication::translate("SettingDlg", "German", nullptr));
        cmbLanguage->setItemText(8, QApplication::translate("SettingDlg", "Italian", nullptr));
        cmbLanguage->setItemText(9, QApplication::translate("SettingDlg", "Portuguese", nullptr));
        cmbLanguage->setItemText(10, QApplication::translate("SettingDlg", "Russian \320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        cmbLanguage->setItemText(11, QApplication::translate("SettingDlg", "Serbian", nullptr));
        cmbLanguage->setItemText(12, QApplication::translate("SettingDlg", "Serbian Latin", nullptr));
        cmbLanguage->setItemText(13, QApplication::translate("SettingDlg", "Spanish", nullptr));
        cmbLanguage->setItemText(14, QApplication::translate("SettingDlg", "Tamil \340\256\244\340\256\256\340\256\277\340\256\264\340\257\215", nullptr));
        cmbLanguage->setItemText(15, QApplication::translate("SettingDlg", "Ukraine \320\243\320\272\321\200\320\260\321\227\320\275\321\201\321\214\320\272\320\270\320\271", nullptr));

        chkUpdates->setText(QApplication::translate("SettingDlg", "Check updates during start application", nullptr));
        btnSave->setText(QApplication::translate("SettingDlg", "Save", nullptr));
        btnCancel->setText(QApplication::translate("SettingDlg", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDlg: public Ui_SettingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDLG_H
