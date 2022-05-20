set terminal pdf
set border linewidth 1.5
set output 'graficos.pdf'
set title "Algoritmos de Ordenação"
set xlabel "Número de pontos"
set logscale y

plot "tempos.txt" u 1:2 w lines lc "blue" title "Bubble Sort"
replot "tempos.txt" u 1:3 w lines lc "green" lw 3 title "Quick Sort"
replot "tempos.txt" u 1:4 w lines lc "red" lw 2 title "Merge Sort"