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

#ifndef SETTINGSDIALOG_HPP
#define SETTINGSDIALOG_HPP

#include <QDialogButtonBox> // Klasa kontrolki z przyciskami dialogu
#include <QPushButton> // Klasa zwyczajnego przycisku
#include <QDialog> // Klasa bazowa dialogu

QT_BEGIN_NAMESPACE
namespace Ui { class SettingsDialog; }  //!< Przestrzeń nazw dla interfejsu dialogu ustawień.
QT_END_NAMESPACE

/*! \brief Dialog ustawień.
 *
 *  Umozliwia ustawienie nowych parametrów losowania.
 *
 */
class SettingsDialog : public QDialog
{

		Q_OBJECT

	public:

		/*! \brief Konstruktor.
		 *  \param [in] min Początkowa wartość minimum.
		 *  \param [in] max Początkowa wartość maksimum.
		 *  \param [in] parent Rodzic okna.
		 *
		 *  Tworzy okno dialogowe z zazdanymi wartościami
		 *  poczatkowymi.
		 *
		 */
		explicit SettingsDialog(
				int min,
				int max,
				QWidget *parent = nullptr);

		/*! \brief Destruktor.
		 *
		 *  Usuwa okno dialogowe i zwalnia użyte zasoby.
		 *
		 */
		virtual ~SettingsDialog(void) override;

	public slots:

		/*! \brief Akceptacja dialogu.
		 *  \see on_accepted.
		 *
		 *  Generuje zdarzenie przekazujace nowe wartości
		 *  i zamyka dialog.
		 *
		 */
		virtual void accept(void) override;

	private slots:

		/*! \brief Walidacja danych.
		 *  \see accept, on_accepted.
		 *
		 *  Sprawdza poprawność danych i w razie potrzeby
		 *  blokuje możliwość akceptacji dialogu.
		 *
		 */
		void on_update(void);

	private:

		Ui::SettingsDialog *ui; //!< Interfejs dialogu.

	signals:

		/*! \brief Zaakceptowano dialog.
		 *  \see accept.
		 *  \param [in] min Nowa wartość minimum.
		 *  \param [in] max Nowa wartość maksimum.
		 *
		 *  Wysyła informacje o nowych wartościach.
		 *
		 */
		void on_accepted(int min, int max);

};

#endif // SETTINGSDIALOG_HPP
