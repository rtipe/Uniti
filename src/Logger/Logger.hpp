//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <functional>
#include <iostream>
#include "json/value.h"

#ifdef _WIN32 || _WIN64
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

namespace Uniti {
    class Logger {
    public:
        enum STATUS {
            LOG,
            WARN,
            DANGER,
            INFO
        };
        enum Color {
            RED,
            BLUE,
            YELLOW,
            WHITE
        };

        /** @brief Constructeur par défaut de la classe Logger.
        */
        Logger();

        /** @brief Destructeur de la classe Logger.
        */
        ~Logger();

        using eventLoggerFunction = std::function<std::string(STATUS status, const std::string &text)>;

        /** @brief Enregistre un message dans le journal avec le statut "LOG".
            @param const std::string &text : Message à enregistrer.
        */
        void Log(const std::string &text);

        /** @brief Enregistre un message dans le journal avec le statut "WARN".
            @param const std::string &text : Message à enregistrer.
        */
        void Warn(const std::string &text);

        /** @brief Enregistre un message dans le journal avec le statut "DANGER".
            @param const std::string &text : Message à enregistrer.
        */
        void Danger(const std::string &text);

        /** @brief Enregistre un message dans le journal avec le statut "INFO".
            @param const std::string &text : Message à enregistrer.
        */
        void Info(const std::string &text);

        /** @brief Affiche un message dans le journal avec le statut spécifié.
            @param STATUS status : Statut du message.
            @param const std::string &text : Message à afficher.
        */
        void Print(STATUS status, const std::string &text);

        /** @brief Surcharge de l'opérateur << pour enregistrer une chaîne de caractères dans le journal.
            @param const std::string &text : Chaîne de caractères à enregistrer.
            @return Logger & : Référence à l'objet Logger.
        */
        Logger &operator<<(const std::string &text);

        /** @brief Surcharge de l'opérateur << pour enregistrer un pointeur de caractère dans le journal.
            @param const char *text : Pointeur de caractère à enregistrer.
            @return Logger & : Référence à l'objet Logger.
        */
        Logger &operator<<(const char *text);

        /** @brief Surcharge de l'opérateur << pour enregistrer un entier dans le journal.
            @param const int &text : Entier à enregistrer.
            @return Logger & : Référence à l'objet Logger.
        */
        Logger &operator<<(const int &text);

        /** @brief Surcharge de l'opérateur << pour enregistrer un nombre à virgule flottante dans le journal.
            @param const float &text : Nombre à virgule flottante à enregistrer.
            @return Logger & : Référence à l'objet Logger.
        */
        Logger &operator<<(const float &text);

        /** @brief Surcharge de l'opérateur << pour enregistrer un entier long dans le journal.
            @param const long &text : Entier long à enregistrer.
            @return Logger & : Référence à l'objet Logger.
        */
        Logger &operator<<(const long &text);

        /** @brief Surcharge de l'opérateur << pour enregistrer un objet JSON dans le journal.
            @param const Json::Value &text : Objet JSON à enregistrer.
            @return Logger & : Référence à l'objet Logger.
        */
        Logger &operator<<(const Json::Value &text);

        /** @brief Ajoute un auditeur d'événements de journalisation associé à un nom donné.
            @param const std::string &name : Nom de l'auditeur d'événements.
            @param eventLoggerFunction function : Fonction d'auditeur d'événements à ajouter.
        */
        void addEventListener(const std::string &name, eventLoggerFunction function);

        /** @brief Modifie le chemin de stockage des journaux.
            @param const std::string &path : Nouveau chemin de stockage.
        */
        void changePath(const std::string &path);

        /** @brief Retourne le chemin de stockage actuel des journaux (lecture/écriture).
            @return std::string & : Référence au chemin de stockage.
        */
        std::string &getPath();

        /** @brief Modifie le statut actuel du journal.
            @param STATUS status : Nouveau statut du journal.
        */
        void changeStatus(STATUS status);

        /** @brief Retourne le statut actuel du journal (lecture seule).
            @return STATUS : Statut actuel du journal.
        */
        STATUS getStatus();

    private:
        void printColor(Color color) {
#ifdef WINVER
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

            switch (color) {
                case RED:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    break;
                case BLUE:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    break;
                case YELLOW:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    break;
                case WHITE:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
                    break;
            }
#else
            switch (color) {
                case RED:
                    std::cout << "\x1B[31m";
                    break;
                case BLUE:
                    std::cout << "\x1B[34m";
                    break;
                case YELLOW:
                    std::cout << "\x1B[33m";
                    break;
                case WHITE:
                    std::cout << "\x1B[37m";
                    break;
                default:
                    std::cout << "\x1B[0m";
                    break;
            }
#endif
        }

        void resetColor() {
#ifdef WINVER
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
#else
            std::cout << "\x1B[0m";
#endif
        }

        std::map<std::string, eventLoggerFunction> _events;
        std::string _path;
        std::stringstream _buffer;
        STATUS _status;
    };
}
