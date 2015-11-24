/**
 * @file common.h
 * @author Lucas Camargo
 * @date Oct 2015
 * @brief File containing common functions.
 */

#pragma once

#define ALLOC_NEW(x) (x *) malloc(sizeof(x)); 

/**
 * @brief clears stdin buffer
 */
void clearstdin();

/**
 * @brief Removes newline from the end of string
 */
void trim(char * buf);
