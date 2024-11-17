#ifndef PPM_H
#define PPM_H

/*
 * Ce header fournit des structures et des fonctions pour initialiser, manipuler et
 * sauvegarder des images PPM.
 */

/* Cette structure stocke les composantes rouge, verte et bleue d'un pixel.
 */
struct ppm_pixel {
    unsigned char r;
    unsigned char g; 
    unsigned char b; 
};

/**Definit les valeurs RGB d'un pixel grace a ppm_pixel
 */
static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r, unsigned char g, unsigned char b)
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
 * alloue de la memoire pour les pixels et définit les dimensions de l'image.
 */
int ppm_image_init(struct ppm_image *im, int w, int h);

/**
     Libere la memoire allouee, et initialiser largeur et longueur a 0.
 */
int ppm_image_release(struct ppm_image *im);


static inline void ppm_image_setpixela(struct ppm_image *im, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    struct ppm_pixel *px = im->px + im->width * y + x;
    ppm_setpixel(px, r, g, b);
}

/**
  Sauvegarde l'image PPM dans un fichier.
 */
int ppm_image_dump(struct ppm_image *im, char *path);

#endif /* PPM_H */

