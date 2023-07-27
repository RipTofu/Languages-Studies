import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int posicion;
        String caracter;

        String espacio_de_juego = "_________";
        boolean victoria = false;



        while(!victoria || espacio_de_juego.contains("_"))
        {
            System.out.print("caracter >> ");
            caracter = scanner.next();
            System.out.print("posicion >> ");
            posicion = scanner.nextInt() - 1 ;
            espacio_de_juego = espacio_de_juego.substring(0, posicion) + caracter + espacio_de_juego.substring(posicion+1);
            System.out.print("---------\n| ");
            System.out.print(espacio_de_juego.charAt(0) + " " + espacio_de_juego.charAt(1) + " " + espacio_de_juego.charAt(2) + " |\n| " );
            System.out.print(espacio_de_juego.charAt(3) + " " + espacio_de_juego.charAt(4) + " " + espacio_de_juego.charAt(5) + " |\n| " );
            System.out.print(espacio_de_juego.charAt(6) + " " + espacio_de_juego.charAt(7) + " " + espacio_de_juego.charAt(8) + " |" );
            System.out.println("\n---------");

            for(int act = 0; act <= 2; act ++) {

                if((espacio_de_juego.charAt(act) == espacio_de_juego.charAt(act+3)) && (espacio_de_juego.charAt(act+3) == espacio_de_juego.charAt(act+6)))
                {
                    if(espacio_de_juego.charAt(act) != '_')
                    {
                        System.out.print(espacio_de_juego.charAt(act) + " wins");
                        victoria = true;
                    }

                }
                else if((espacio_de_juego.charAt(act * 3) == espacio_de_juego.charAt(act * 3 + 1)) && (espacio_de_juego.charAt(act * 3 + 1) == espacio_de_juego.charAt(act * 3 + 2)))
                {
                    if(espacio_de_juego.charAt(act) != '_')
                    {
                        System.out.print(espacio_de_juego.charAt(act) + " win");
                        victoria = true;
                    }

                }
                else if(act != 1)
                {
                    if(espacio_de_juego.charAt(act) == espacio_de_juego.charAt(act+4))
                    {
                        if(act == 0)
                        {
                            if(espacio_de_juego.charAt(8) == espacio_de_juego.charAt(4))
                            {
                                if(espacio_de_juego.charAt(act) != '_')
                                {
                                    System.out.print(espacio_de_juego.charAt(act) + " wins");
                                    victoria = true;
                                }

                            }
                        }
                        else {
                            if(espacio_de_juego.charAt(6) == espacio_de_juego.charAt(4))
                            {
                                if(espacio_de_juego.charAt(act) != '_')
                                {
                                    System.out.print(espacio_de_juego.charAt(act) + " wins");
                                    victoria = true;
                                }

                            }
                        }
                    }
                }

            }
        }
        System.out.print("draw");




    }
}
