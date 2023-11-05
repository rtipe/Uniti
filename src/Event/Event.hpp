//
// Created by youba on 25/10/2023.
//

#pragma once

#include <functional>
#include "json/value.h"
#include "Logger.hpp"

namespace Uniti {
    using eventFunction = std::function<void(const Json::Value &value)>;
    class Event {
    public:
        /** @brief Ajoute une fonction d'événement associée à un nom donné.
            @param const std::string &name : Nom de l'événement.
            @param eventFunction function : Fonction d'événement à ajouter.
            @return std::size_t : Identifiant unique de la fonction d'événement ajoutée.
        */
        std::size_t addEvent(const std::string &name, eventFunction function);

        /** @brief Supprime toutes les fonctions d'événement associées à un nom donné.
            @param const std::string &name : Nom de l'événement à supprimer.
        */
        void removeEvent(const std::string &name);

        /** @brief Supprime une fonction d'événement spécifique associée à un nom donné.
            @param const std::string &name : Nom de l'événement.
            @param std::size_t id : Identifiant unique de la fonction d'événement à supprimer.
        */
        void removeEvent(const std::string &name, std::size_t id);

        /** @brief Émet un événement spécifique avec des données JSON associées.
            @param const std::string &name : Nom de l'événement à émettre.
            @param const Json::Value &value : Données JSON associées à l'événement.
            @param Logger &logger : Objet de journalisation pour enregistrer des informations.
        */
        virtual void emitEvent(const std::string &name, const Json::Value &value, Logger &logger);

    private:
        std::map<std::string, std::vector<eventFunction>> _events;
    };
}
