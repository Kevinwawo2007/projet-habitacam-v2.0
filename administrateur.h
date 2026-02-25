/* ============================================================
 *  HabitatCam — Plateforme de logement au Cameroun
 *  Fichier     : administrateur.h
 *  Version     : 1.0
 *  Description : Module Administrateur — gestion des utilisateurs
 *                et des logements depuis le panneau admin.
 * ============================================================ */

#ifndef ADMINISTRATEUR_H_INCLUDED
#define ADMINISTRATEUR_H_INCLUDED

#include "Structure.h"

/* ── Fonctions principales du menu admin ───────────────────── */

/* Point d'entrée du module — affiche le menu administrateur */
void menuAdministrateur();

/* ── Gestion des utilisateurs ──────────────────────────────── */

/* Affiche la liste de tous les utilisateurs inscrits */
void adminVoirUtilisateurs();

/* Désactive ou réactive le compte d'un utilisateur (par ID) */
void adminToggleCompte();

/* Supprime définitivement un utilisateur (par ID) */
void adminSupprimerUtilisateur();

/* ── Gestion des logements ─────────────────────────────────── */

/* Affiche tous les logements (disponibles et réservés) */
void adminVoirLogements();

/* Supprime un logement de la plateforme (par ID) */
void adminSupprimerLogement();

/* ── Statistiques ──────────────────────────────────────────── */

/* Affiche un résumé : nb utilisateurs, nb logements, nb réservations */
void adminStatistiques();

#endif /* ADMINISTRATEUR_H_INCLUDED */
