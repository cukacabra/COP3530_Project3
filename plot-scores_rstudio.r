# load ggplot2
library(ggplot2)

score_file <- 'C:\\Users\\NAME\\Documents\\GitHub\\COP3530_Project\\output\\scores2.csv'

scores <- read.csv(score_file)

ggplot(scores, aes(reorder(Airline, 1 / Score), Score)) +
  geom_bar(aes(alpha = Number),
           stat = 'identity',
           fill = 'darkgreen',
           color = 'darkgreen') +
  theme_bw() + labs(
    alpha = 'Num of flights',
    x = 'Airline',
    y = 'Score',
    title = 'Airline Scores'
  )

