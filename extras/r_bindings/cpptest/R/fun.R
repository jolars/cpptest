#' Add Vectors
#'
#' This function adds two vectors together.
#'
#' @param a A vector.
#' @param b A vector.
#'
#' @return A vector that is the sum of a and b.
#'
#' @export
#'
#' @examples
#' add_vectors(c(1, 2, 3), c(4, 5, 6))
add_vectors <- function(a, b) {
  add_vectors_cpp(a, b)
}
