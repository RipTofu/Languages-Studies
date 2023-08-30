var cantidad = prompt("Ingresar cantidad de estudiantes: ");
var estudiantes = [];
var finales = [];
var aprobados = 0;
var reprobados = 0;

for(i = 1 ; i <= cantidad ; i++)
{
  var notas = [];
  for(j = 1 ; j <= 4 ; j++)
  {
    var nota = Number(prompt("Ingresar nota " + j + " del estudiante " + i));
    notas.push(nota);
  }
  var final = notas[0] * 0.15 + notas[1] * 0.2 + notas[2] * 0.25 + notas[3] * 0.4;
  finales.push(final);
  estudiantes.push(notas);
}
var suma = 0.0;
for(l = 0 ; l < finales.length ; l++)
{
  suma = suma + finales[l];
  console.log(suma);
  if(finales[l] <= 4.0)
  {
    reprobados ++;
  }
  else
  {
    aprobados++;
  }
}
const promedio = suma / finales.length;
console.log("Nota final del curso: " + promedio + "\nAprobados: " + aprobados + "\nReprobados: " + reprobados);
