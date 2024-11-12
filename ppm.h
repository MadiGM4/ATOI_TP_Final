#ifndef PPM_H
#define PPM_H

/*
 * Ce header fournit des structures et des fonctions pour initialiser, manipuler et
 * sauvegarder des images PPM. Le format PPM est un format simple d'image bitmap
 * avec des composantes rouge, verte et bleue (RGB) pour chaque pixel.
 */

/*
 * Cette structure stocke les composantes rouge, verte et bleue d'un pixel.
 */
struct ppm_pixel {
    unsigned char r;
    unsigned char g; 
    unsigned char b; 
};

/**
 * brief Définit les valeurs RGB d'un pixel.
 */
static inline void ppm_setpixel(
        struct ppm_pixel *px,
        unsigned char r, unsigned char g, unsigned char b)
{
    px->r = r;
    px->g = g;
    px->b = b;
}

/*
 * Cette structure contient les dimensions de l'image et un tableau de pixels.
 */
struct ppm_image {
    unsigned int width;  /**< Largeur de l'image */
    unsigned int height; /**< Hauteur de l'image */
    struct ppm_pixel *px; /**< Tableau de pixels */
};

/*
 * Alloue la mémoire pour les pixels et définit les dimensions de l'image.
 */
int ppm_image_init(struct ppm_image *im, int w, int h);

/**
     Libère la mémoire allouée pour une image PPM.
 */
int ppm_image_release(struct ppm_image *im);

/*
  Définit un pixel à des coordonnées spécifiques dans une image.
 */
static inline void ppm_image_setpixela(
        struct ppm_image *im, int x, int y,
        unsigned char r, unsigned char g, unsigned char b)
{
    struct ppm_pixel *px = im->px + im->width * y + x;
    ppm_setpixel(px, r, g, b);
}

/**
  Sauvegarde l'image PPM dans un fichier.
 */
int ppm_image_dump(struct ppm_image *im, char *path);

#endif /* PPM_H */

