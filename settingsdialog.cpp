/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Program symulujący rzut kostką                                         *
 *  Copyright (C) 2020  Łukasz "Kuszki" Dróżdż  lukasz.kuszki@gmail.com    *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the  Free Software Foundation, either  version 3 of the  License, or   *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This  program  is  distributed  in the hope  that it will be useful,   *
 *  but WITHOUT ANY  WARRANTY;  without  even  the  implied  warranty of   *
 *  MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.  See  the   *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have  received a copy  of the  GNU General Public License   *
 *  along with this program. If not, see http://www.gnu.org/licenses/.     *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "settingsdialog.hpp" // Nagłówek okna dialogowego
#include "ui_settingsdialog.h" // Wygenerowany interfejs

SettingsDialog::SettingsDialog(int min, int max, QWidget *parent) :
	QDialog(parent), // Wywołanie konstruktora klasy bazowej
	ui(new Ui::SettingsDialog) // Utworzenie obiektu interfejsu
{
	ui->setupUi(this); // Budowanie interfejsu

	// Połaczenie zdarzenia zmiany wartości
	// z obsługą walidacji danych dialogu
	connect(ui->spinMin, qOverload<int>(&QSpinBox::valueChanged),
		   this, &SettingsDialog::on_update);

	// Połaczenie zdarzenia zmiany wartości
	// z obsługą walidacji danych dialogu
	connect(ui->spinMax, qOverload<int>(&QSpinBox::valueChanged),
		   this, &SettingsDialog::on_update);

	// Ustawienie wartości początkowych
	ui->spinMin->setValue(min);
	ui->spinMax->setValue(max);
}

SettingsDialog::~SettingsDialog(void)
{
	delete ui; // Usunięcie interfejsu
}

void SettingsDialog::accept(void)
{
	QDialog::accept(); // Wykonanie domyślnego zachowania dialogu

	// Wygenerowanie zdarzenia informującego o nowych wartościach
	emit on_accepted(
			ui->spinMin->value(),
			ui->spinMax->value());
}

void SettingsDialog::on_update(void)
{
	// Obliczenie, czy dane są poprawnie wprowadzone
	bool ok = ui->spinMin->value() < ui->spinMax->value();

	// Ustawienie aktywności przycisku akceptacji dialogu
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}
