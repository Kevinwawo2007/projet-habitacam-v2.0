/* ============================================================
 * @file    win_admin.h
 * @brief   Declarations du module graphique Administrateur
 *          HabitatCam V3.0 — Interface Win32
 *
 * A inclure dans :
 *   - main_win32.c   (pour appeler pageAdmin et gererClicAdmin)
 *   - tout fichier qui utilise les fonctions de ce module
 *
 * @version 3.0
 * @author  TOGNANG — HabitatCam V3.0
 * ============================================================ */

#ifndef WIN_ADMIN_H_INCLUDED
#define WIN_ADMIN_H_INCLUDED

#include <windows.h>

/* ============================================================
 * IDENTIFIANTS DES CONTROLES — PLAGE RESERVEE : 3000 - 3099
 * Ne pas utiliser ces valeurs dans les autres modules.
 * ============================================================ */

/* Labels / barres */
#define ID_ADM_TITRE        3000
#define ID_ADM_NOM_ADMIN    3001
#define ID_ADM_STATUS_BAR   3002

/* Boutons de la sidebar */
#define ID_ADM_BTN_USERS    3010   /* Voir les utilisateurs        */
#define ID_ADM_BTN_TOGGLE   3011   /* Activer / Desactiver compte  */
#define ID_ADM_BTN_REACTIV  3012   /* Reactiver compte verrouille  */
#define ID_ADM_BTN_DEL_USR  3013   /* Supprimer un utilisateur     */
#define ID_ADM_BTN_LOGS     3014   /* Voir les logements           */
#define ID_ADM_BTN_DEL_LOG  3015   /* Supprimer un logement        */
#define ID_ADM_BTN_STATS    3016   /* Statistiques generales       */
#define ID_ADM_BTN_DEMANDES 3017   /* Demandes reinit. mot de passe*/
#define ID_ADM_BTN_DECONN   3018   /* Se deconnecter               */

/* ListView principal */
#define ID_ADM_LISTVIEW     3020

/* ============================================================
 * FONCTIONS PUBLIQUES DU MODULE
 * ============================================================ */

/**
 * @brief  Cree tous les controles de la page administrateur.
 *
 * Doit etre appelee UNE SEULE FOIS dans le WM_CREATE
 * de la fenetre principale (main_win32.c), apres la creation
 * des polices et des pinceaux globaux.
 *
 * Tous les controles sont crees caches (SW_HIDE).
 * Appelez allerA(PAGE_ADMIN) pour les afficher.
 *
 * Exemple dans WndProc :
 *   case WM_CREATE:
 *       ...
 *       pageAdmin();
 *       ...
 */
void pageAdmin(void);

/**
 * @brief  Gere les clics de boutons de la page administrateur.
 *
 * Doit etre appelee dans le WM_COMMAND de la fenetre principale,
 * quand pageCourante == PAGE_ADMIN.
 *
 * Exemple dans WndProc :
 *   case WM_COMMAND:
 *       if(pageCourante == PAGE_ADMIN)
 *           gererClicAdmin((int)LOWORD(wParam));
 *       break;
 *
 * @param id  Identifiant du bouton clique (LOWORD de wParam).
 */
void gererClicAdmin(int id);

/**
 * @brief  Gere le dessin des boutons colores de la sidebar admin.
 *
 * Doit etre appelee dans le WM_DRAWITEM de la fenetre principale,
 * quand pageCourante == PAGE_ADMIN.
 *
 * Exemple dans WndProc :
 *   case WM_DRAWITEM:
 *       if(pageCourante == PAGE_ADMIN)
 *           return gererDrawItemAdmin(wParam, lParam);
 *       break;
 *
 * @param wP  wParam du message WM_DRAWITEM.
 * @param lP  lParam du message WM_DRAWITEM.
 * @return    TRUE si le bouton a ete dessine, FALSE sinon.
 */
LRESULT gererDrawItemAdmin(WPARAM wP, LPARAM lP);

#endif /* WIN_ADMIN_H_INCLUDED */
