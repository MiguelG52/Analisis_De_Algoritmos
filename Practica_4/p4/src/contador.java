 /*INSTITUTO POLITÉCNICO NACIONAL
   ESCUELA SUPERIOR DE CÓMPUTO
   ALUMNOS: González Hipólito Miguel Angel, Lechuga Canales Héctor Jair
   GRUPO: 3CV11
   MATERIA: Análisis de algortmos
   PROFESOR: Benjamin Luna Benoso 
   FECHA: 1/11/2022
   PRÁCTICA 3: Funciones Iterativas vs recursivas*/
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class contador {

    static int pasos = 0;
    public static void main(String[] args) throws Exception {
        // cambiale aqui el numero de casos que quieres que imprima
        int t = 500;
        FileWriter fs = new FileWriter("out.csv");
        BufferedWriter bw = new BufferedWriter(fs);
        PrintWriter pw = new PrintWriter(bw);
        try {
            for(int i=0; i<t;i++){
                double e = (int)(Math.random()*(12-0+1));
                int medida = (int)  Math.pow(2, e);
    
                proceso(pasos, medida);
                System.out.print("medida:"+medida+"x"+medida+"\tpasos:"+pasos+"\n");
                pw.print(medida);
                pw.print(",");
                pw.println(pasos);
                pw.flush();
                pasos = 0;
            }  
        } catch (Exception e) {
            
        }
        pw.close();
    }
    public static void proceso(int pasos, int medida){
        int width = medida;
        int height = width;
        try{
            int [][] matriz = new int[width][height];
            
            //Genera matriz de valores argb
            for(int i = 0; i<height; i++){
                for(int j=0;j <width; j++)
                {
                    matriz[i][j] = 1;
                }
            }

            tranpuesta(matriz, 0, matriz.length-1, 0, matriz.length-1);

        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }

    //intercambia posiciones en matrices, hacieno a = a^t
    public static void swap(int[][] m, int fIniA, int cIniA, int fIniB, int cIniB, int d){
        pasos++;
        for(int i=0; i<d; i++)
        { 
            pasos++;
            for(int j=0; j<d; j++ )
            {
                pasos++;
                int temp = m[fIniA+i][cIniA+j];pasos++;
                m[fIniA+i][cIniA+j] = m[fIniB+i][cIniB+j];pasos++;
                m[fIniB+i][cIniB+j] = temp;pasos++;
                pasos++;
            }
            pasos++;
        }
        pasos++;
        pasos++;
    }

    //divide una matriz en 4 submatrices de forma recursiva
    public static void tranpuesta(int[][] m, int fInicio, int fFin, int cInicio, int cFin){
        pasos++;
        if(fInicio<fFin){
            int fMedio = (fInicio+fFin)/2; pasos++;
            int cMedio = (cInicio+cFin)/2; pasos++;
            tranpuesta(m, fInicio, fMedio, cInicio, cMedio);
            tranpuesta(m, fInicio, fMedio, cMedio+1, cFin);
            tranpuesta(m, fMedio+1, fFin, cInicio, cMedio);
            tranpuesta(m, fMedio+1, fFin, cMedio+1, cFin);
            swap(m, fMedio+1, cInicio, fInicio, cMedio+1, fFin-fMedio);
        }
    }
}
