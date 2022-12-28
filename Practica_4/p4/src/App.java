 /*INSTITUTO POLITÉCNICO NACIONAL
   ESCUELA SUPERIOR DE CÓMPUTO
   ALUMNOS: González Hipólito Miguel Angel, Lechuga Canales Héctor Jair
   GRUPO: 3CV11
   MATERIA: Análisis de algortmos
   PROFESOR: Benjamin Luna Benoso 
   FECHA: 1/11/2022
   PRÁCTICA 3: Funciones Iterativas vs recursivas*/
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;



public class App {

    static int pasos;
    static int medida;

    public static void main(String[] args) throws Exception {

        try{
            //Almacenamos imagen en buffer
            BufferedImage img = ImageIO.read(new File("img_24.bmp")); //Aqui cambiale a cualquiera imagen que tengas que sea 24 bits
            
            //Valida si la imagen tiene una salida de colores de 24 bits y si es del mismo tamaño en alto y ancho
            if(img.getColorModel().getPixelSize() != 24) throw new IOException("La imagen debe tener una profundidada de 24 bits");
            int width = img.getWidth();
            int height = img.getHeight();
            if(width%2 != 0 && height%2 !=0 && width!=height) throw new IOException("La imagen debe tener el mismo ancho y alto");

            int [][] matriz = new int[width][height];
            
            //Genera matriz de valores argb
            for(int i = 0; i<height; i++){
                for(int j=0;j <width; j++)
                {
                    int pixel = img.getRGB(i,j);
                    matriz[i][j] = pixel;
                }
            }

            tranpuesta(matriz, 0, matriz.length-1, 0, matriz.length-1);
            
            //recorre el alcho y alto de la imgen e inserta los valores rgb en el buffer creado dependiendo su valor rgb
            for(int i = 0; i<height; i++){
                for(int j=0;j <width; j++)
                {
                    int pixel = (matriz[i][j]<<16) | (matriz[i][j]<<8) | matriz[i][j];
                    img.setRGB(i,j,pixel);
                }
            }
            
            //Crea imagen
            File output = new File("output.bmp");
            ImageIO.write(img, "bmp", output);


        }catch(IOException e){
            System.out.println(e.getMessage());
        }


    }

    //intercambia posiciones en matrices, hacieno a = a^t
    public static void swap(int[][] m, int fIniA, int cIniA, int fIniB, int cIniB, int d){
        for(int i=0; i<d; i++)
        {
            for(int j=0; j<d; j++ )
            {
                int temp = m[fIniA+i][cIniA+j];
                m[fIniA+i][cIniA+j] = m[fIniB+i][cIniB+j];
                m[fIniB+i][cIniB+j] = temp;
            }
        }
    }

    //divide una matriz en 4 submatrices de forma recursiva
    public static void tranpuesta(int[][] m, int fInicio, int fFin, int cInicio, int cFin){
        if(fInicio<fFin){
            int fMedio = (fInicio+fFin)/2;
            int cMedio = (cInicio+cFin)/2;
            tranpuesta(m, fInicio, fMedio, cInicio, cMedio);
            tranpuesta(m, fInicio, fMedio, cMedio+1, cFin);
            tranpuesta(m, fMedio+1, fFin, cInicio, cMedio);
            tranpuesta(m, fMedio+1, fFin, cMedio+1, cFin);
            swap(m, fMedio+1, cInicio, fInicio, cMedio+1, fFin-fMedio);
        }
    }
}
