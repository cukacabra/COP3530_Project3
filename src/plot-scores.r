library(optparse)

option_list <- list(
  make_option(c("-s", "--scores"), 
              type = "character",
              help = "Airline scores in CSV [Airline,Score,Number]"),
  make_option(c("-o", "--output_dir"),
              type = "character",
              default = ".",
              help = "Output directory")
)

opt <- parse_args(OptionParser(option_list = option_list))

# stop if file doesn't exist
stopifnot(file.exists(opt$scores))
stopifnot(file.exists(opt$output_dir))

# load ggplot2
suppressPackageStartupMessages({
  library(ggplot2)
})

# scores <- read.csv('~/proj/COP3530_Project3-test/output/scores2.csv')
scores <- read.csv(opt$scores)

plot <- ggplot(scores, aes(reorder(Airline, 1 / Score), Score)) +
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

output_file <- file.path(opt$output_dir, paste0(basename(opt$scores), '.png'))

ggsave(filename = output_file, plot)
