
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.Vector;
public class App {

    static int contador=0;
    
    private static double getMaxValue(Vector<Item> arr ,int capacity){
        
        double totalValue = 0d; contador++;

        arr.sort(new Comparator<Item>(){
            @Override
            public int compare(Item i1, Item i2){
                double cpr1 = (double) i1.getValue() / (double)i1.getWeigth(); contador++;
                double cpr2 = (double) i2.getValue() / (double)i2.getWeigth(); contador++;
                
                contador++;
                contador++;
                if (cpr1 < cpr2) 
                    return 1;
                else
                    return -1;
            }
        });
        
        for(Item i:arr){
            
            int curWt = (int)i.getWeigth(); contador++;
            int curVal = (int)i.getValue(); contador++;
            contador++;
            if (capacity - curWt >= 0) {

                capacity = capacity - curWt; contador++;
                totalValue += curVal; contador++;
            }
            else {
                double fraction = ((double)capacity / (double)curWt); contador++;
                totalValue += (curVal * fraction); contador++;
                capacity = (int)(capacity - (curWt * fraction)); contador++;
                contador++;
                break;
            }
        }
        contador++;
        int temp = (int) contador;
        contador = (int)(temp * Math.log10(arr.size()));
        return totalValue;
    }
    public static int getRandomIntegerBetweenRange(int min, int max){
        int x = (int)(Math.random()*((max-min)+1))+min;
        return x;
    }
    public static void llenaArreglo(Vector<Item>arr, int elements){
        for(int i = 0; i<elements;i++){
            int w = getRandomIntegerBetweenRange(1, 400);
            int v = getRandomIntegerBetweenRange(0, 100);
            arr.add(new Item(v, w));
        }
    }

    public static void main(String[] args) throws Exception
    {

        FileWriter fs = new FileWriter("out.csv");
        BufferedWriter bw = new BufferedWriter(fs);
        PrintWriter pw = new PrintWriter(bw);
 
        try {
            for(int t=0;t<1000;t++){
                Vector<Item> arr = new Vector<Item>();
                int elements = getRandomIntegerBetweenRange(0, 500);
                int capacity = getRandomIntegerBetweenRange(1, 200);
                llenaArreglo(arr, elements);
    
                double maxValue = getMaxValue(arr, capacity);
                System.out.append(maxValue+"\t"+"\n");
                pw.print(elements);
                pw.print(",");
                pw.println(contador);
                pw.flush();
                contador = 0;
            }
            pw.close();
        } catch (Exception e) {
            System.out.print(e);
        }
    }
}
 