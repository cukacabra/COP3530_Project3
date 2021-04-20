# A++ Flights
This program requires the installation of R and the location of your Rscript.exe directory. (e.g. `C:\"Program Files"\R\R-4.0.5\bin\Rscript.exe`)

If this does not work:
1. Execute `aplusplus.exe` to generate `scores2.csv`
2. Open `cmd`, `cd` to COP3530_Project (e.g. `C:\Users\NAME\Documents\GitHub\COP3530_Project`)
3. Run `C:\"Program Files"\R\R-4.0.5\bin\Rscript.exe plot-scores.r -s output/scores2.csv -o output` with the directory of your Rscript.exe


OR


2. Open `plot-score_rstudio.r` in RStudio and replace the directory of `scores2.csv` with your own
3. Run RStudio



### Dependencies:
* optparse
* ggplot2

![Graph of Airline Scores](output/scores2.csv.png?raw=true)
