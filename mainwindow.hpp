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

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QRandomGenerator> // Generowanie liczb pseudolosowych
#include <QMainWindow> // Baza głównego okna aplikacji
#include <QSettings> // Klasa obsługująca ustawienia

#include "settingsdialog.hpp" // Własny dialog ustawień

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } //!< Przestrzeń nazw dla interfejsu okna głównego.
QT_END_NAMESPACE

/*! \brief Okno główne.
 *
 *  Klasa implementujaca działanie okna głównego.
 *
 */
class MainWindow : public QMainWindow
{

		Q_OBJECT

	public:

		/*! \brief Konstruktor.
		 *  \param [in] parent Rodzic okna.
		 *
		 *  Tworzy okno aplikacji wraz z jego zawartością.
		 *
		 */
		explicit MainWindow(QWidget *parent = nullptr);

		/*! \brief Destruktor.
		 *
		 *  Usuwa okno główne i zwalnia użyte zasoby. Podczas
		 *  zamykania obecne ustawienia są zachowywane do pliku.
		 *
		 */
		virtual ~MainWindow(void) override;

	private:

		Ui::MainWindow *ui; //!< Interfejs okna.

		int m_min = 1; //!< Wartość minimum.
		int m_max = 6; //!< Wartość maksimum.

	private slots:

		/*! \brief Nacisnięto losuj.
		 *
		 *  Obsługuje zdarzenie wciśnięcia przycisku losuj.
		 *  Wyświetla na ekranie wylosowaną wartość.
		 *
		 */
		void on_roll_clicked(void);

		/*! \brief Nacisnięto opcje.
		 *
		 *  Obsługuje zdarzenie wciśnięcia przycisku opcje.
		 *  Wyświetla na ekranie dialog ustawień.
		 *
		 */
		void on_options_clicked(void);

		/*! \brief Zaakceptowano dialog.
		 *  \see m_min, m_max.
		 *  \param [in] min Nowa wartość minimum.
		 *  \param [in] max Nowa wartość maksimum.
		 *
		 *  Obsługuje zdarzenie akceptacji dialogu.
		 *  Aktualizuje parametry losowania.
		 *
		 */
		void on_dialog_accepted(int min, int max);

};
#endif // MAINWINDOW_HPP
