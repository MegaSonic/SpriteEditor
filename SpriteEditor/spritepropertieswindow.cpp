#include <QDialogButtonBox>
#include "spritepropertieswindow.h"
#include "ui_spritepropertieswindow.h"

SpritePropertiesWindow::SpritePropertiesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpritePropertiesWindow),
    isAccepted(false),
    cancelEnabled(false)
{
    mainWindowRef = static_cast<MainWindow *>(parent);
    ui->setupUi(this);
}

SpritePropertiesWindow::~SpritePropertiesWindow()
{
    delete ui;
}

void SpritePropertiesWindow::enableCancel()
{
    cancelEnabled = true;
}


void SpritePropertiesWindow::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button->text() == QString("OK"))
    {
        ui->errorMessage->setText("");
        if(ui->projectNameLineEdit->text().isEmpty())
        {
            ui->errorMessage->setText("Project needs a name.");
            return;
        }

        if(this->ui->spriteSizeSpinBox->value() < 8 || ui->spriteSizeSpinBox->value() > 256)
        {
            ui->errorMessage->setText("Size must be between 8 and 256");
            return;
        }

        isAccepted = true;

        if (isAccepted)
        {
//            mainWindowRef->spriteSize = this->ui->spriteSizeSpinBox->value();
//            mainWindowRef->setProjectName(this->ui->projectNameLineEdit->text());
        }
    }
    else
    {
        if(cancelEnabled)
        {
            this->hide();
        }
    }
}
