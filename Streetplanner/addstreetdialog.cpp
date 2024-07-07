#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"

/**
 * @brief AddStreetDialog::AddStreetDialog
 * @param map
 * @param parent
 */
AddStreetDialog::AddStreetDialog(Map *map, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStreetDialog)
{
    ui->setupUi(this);
}

/**
 * @brief AddStreetDialog::~AddStreetDialog
 */
AddStreetDialog::~AddStreetDialog()
{
    delete ui;
}

/**
 * @brief AddStreetDialog::getCityFrom
 * @return Returns the city name the street starts from.
 */
QString AddStreetDialog::getCityFrom() {
    return ui->input_City_from->text();
}

/**
 * @brief AddStreetDialog::getCityTo
 * @return Returns the city name the street ends at.
 */
QString AddStreetDialog::getCityTo() {
    return ui->input_City_to->text();
}

/**
 * @brief Creates a new street object with the input values
 *
 * @return Street*
 */
Street* AddStreetDialog::createStreet() {
    City *From = map->findCity(getCityFrom());
    City *To = map->findCity(getCityTo());
    Street *street = new Street(From, To);
    return street;
}

/**
 * @brief Checks if the input is valid.
 *
 * @return true if the input is valid.
 */
bool AddStreetDialog::isInputValid() {
    qDebug() << "1";
    if(getCityFrom().isEmpty()) return false;
    qDebug() << "2";
    if(getCityTo().isEmpty()) return false;
    qDebug() << "3";
    if(map->findCity(getCityFrom()) == NULL) return false;
    qDebug() << "4";
    if(map->findCity(getCityTo()) == NULL) return false;
    qDebug() << "5";

    return true;
}

/**
 * @brief AddStreetDialog::on_buttonBox_accepted
 */
void AddStreetDialog::on_buttonBox_accepted() {
    if(isInputValid()) {
        done(QDialog::Accepted);
        qDebug() << "The input is valid.";
    } else {
        done(2);
        qDebug() << "The input is invalid.";
    }
}

void AddStreetDialog::on_buttonBox_rejected() {
    qDebug() << "The input was cancelled";
    done(QDialog::Rejected);
}
