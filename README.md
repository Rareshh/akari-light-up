# Akari (Light Up) Puzzle Solver

## Overview

This project implements the logic for the `Akari puzzle`. The program processes
a grid to either assist in solving the puzzle (by marking illuminated areas)
or to validate a specific configuration against the game rules.

## Project Structure

* `akari.c`: Main entry point. Handles input/output and controls the execution flow.
* `akari_functions.c`: Contains the core logic functions for light propagation
  (gridL) and numeric constraint checking (grid0 - grid3).
* `akari_headers.h`: Header file defining function prototypes and constants.
* `Makefile`: Automation script for compilation and cleanup.

## Functionality

The program accepts an option (1 or 2) followed by the grid dimensions and the
map data.

## Option 1: Solving Assistance

Marks cells where bulbs cannot be placed.

Light Propagation: Extends light from every bulb ('L') horizontally and
vertically, marking empty cells as 'x' (illuminated).

Constraint Marking: Analyzes numbered black cells (0-3). If a cell has satisfied
its bulb requirement, adjacent empty spots are marked as unavailable ('x') to
prevent rule violations.

## Option 2: Grid Validation

Checks if the current grid configuration is a valid solution.

Collision Detection: Ensures no two bulbs illuminate each other.

Numeric Validation: Verifies that every numbered black cell has exactly the
required number of adjacent bulbs.

Output: Prints ichi if valid, or zero if invalid.

#### **Created by Spinu Rares.**
