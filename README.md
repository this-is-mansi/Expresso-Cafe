# Expresso Cafe Project

## Overview

Expresso Cafe is a graphical application developed in C++ using C graphics. It simulates a cafe ordering system with an interactive graphical user interface, allowing users to place orders, view the menu, and process payments.

## Features

- Interactive graphical user interface using C graphics (graphics.h)
- Menu display with categorized items
- UI for order placements
- Combo placements for special offers
- Navigation between menu sections
- Bill generation and display
- Smooth animations and transitions for user experience

## Technologies Used

- C++
- C Graphics

## Setup Instructions

1. Install a C++ compiler (Turbo C++, Dev-C++, or any compiler supporting graphics.h)
2. Ensure `graphics.h`, `winbgim.h`, and `libbgi.a` are set up in your compiler.
3. Clone the repository:
   ```bash
   git clone https://github.com/your-username/expresso-cafe.git
   cd expresso-cafe
   ```
4. Compile the project:
   ```bash
   g++ expresso_cafe.cpp -o expresso_cafe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
   ```
5. Run the executable:
   ```bash
   ./expresso_cafe
   ```

## Usage

- Navigate the menu using keyboard or mouse interactions.
- Select items and quantities to place an order.
- View the total bill before confirming the purchase.
- Exit the application after completion.

## Future Enhancements

- Add sound effects for a more immersive experience.
- Implement a database for order history tracking.
- Improve UI aesthetics with better fonts and themes.

## Contributors

- **Mansi Kothale** (Developer)

## License

This project is open-source under the MIT License.
