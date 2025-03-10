### `Advanced Graph Processing`
### `ניתוח ומניפולציה על גרפים `
### `Graph.hpp`
1. **`Graph()`**:

   - קונסטרוקטור הבנאי של הגרף .

2. **`~Graph()`**:

   - דיסטרוקטור פירוק הגרף .

3. **`loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix) -> void`**:

   - טוען את הגרף ממטריצת הסמיכות הנתונה.
   - מטריצת הסמיכות מייצגת את הקשרים בין קודקודים, כאשר ערך שאינו אפס ב- `matrix[i][j]` מציין קצה מקודקוד `i` לקודקוד `j`.

4. **`printGraph() const -> void`**:

   - מדפיס את הגרף (למטרות איתור באגים).
   - הוא מדפיס כל קודקוד ואת הקודקודים הסמוכים לו.

5. **`getNumVertices() const -> int`**:

   - מחזירה את מספר הקודקודים בגרף.

6. **`getNumEdges() const -> int`**:

   - מחזירה את מספר הקצוות בגרף.

7. **`containsEdge(unsigned int u, unsigned int v) const -> bool`**:

   - בודק אם יש קצה מקודקוד `u` לקודקוד `v`.

8. **`getNeighbors(unsigned int u, int& size) const -> int*`**:

   - מחזירה מערך של שכנים של קודקוד 'u'.
   - הפרמטר 'גודל' משמש לאחסון גודל המערך המוחזר.

9. **`getWeight(unsigned int u, unsigned int v) const -> int`**:

   - מחזיר את משקל הקצה מקודקוד `u` לקודקוד `v`.

10. **אופרטורים אריתמטיים**:

    - **הוספה**: `אופרטור גרף+(const Graph& other) const`, `Graph&operator+=(const Graph& other)`
    - **חיסור**: `אופרטור גרף-(const Graph& other) const`, `Graph&operator-=(const Graph& other)`
    - **Unary**: `אופרטור גרף+() const`, `אופרטור גרף-() const`

11. **אופרטורי השוואה**:

    - `bool operator==(const Graph& other) const`
    - `bool operator!=(const Graph& other) const`
    - `אופרטור bool<(const Graph& other) const`
    - `אופרטור bool<=(const Graph& other) const`
    - `bool operator>(const Graph& other) const`
    - `bool operator>=(const Graph& other) const`

12. **אופרטורים להגדלה והקטנה**:

    - **תוספת**: `Graph& operator++()`, `Graph operator++(int)`
    - **הפחתה**: `Graph& operator--()`, `Graph operator--(int)`

13. **כפל סקלרי**:

    - `אופרטור גרף*(int scalar) const`
    - `Graph& operator*=(int scalar)`

14. **כפל גרפים**:

    - `אופרטור גרף*(const Graph& other) const`

15. **אופרטור פלט**:
    - `חבר std::ostream& אופרטור<<(std::ostream& os, const Graph& graph)`

### `Graph.cpp`

1. **`Graph::Graph()`:**

   - קונסטרוקטור הבנאי של הגרף .

2. **`Graph::~Graph()`:**

   - דיסטרוקטור פירוק הגרף .

3. **`Graph::loadGraph(const std::vector<std::vector<int>> &adjacencyMatrix) -> void`:**

   - טוען את הגרף ממטריצת הסמיכות הנתונה.
   - מאמת את המטריצה כדי להבטיח שהיא מייצגת מבנה גרף חוקי.

4. **`Graph::printGraph() const -> void`:**

   - מדפיס את הגרף (למטרות איתור באגים).
   - פלט כל קודקוד והקודקודים הסמוכים לו.

5. **`Graph::getNumVertices() const -> int`:**

   - מחזירה את מספר הקודקודים בגרף.

6. **`Graph::getNumEdges() const -> int`:**

   - מחזירה את מספר הקצוות בגרף.

7. **`Graph::containsEdge(unsigned int u, unsigned int v) const -> bool`:**

   - בודק אם יש קצה מקודקוד `u` לקודקוד `v`.

8. **`Graph::getNeighbors(unsigned int u, int &size) const -> int*`:**

   - מחזירה מערך של שכנים של קודקוד 'u'.
   - הפרמטר 'גודל' משמש לאחסון גודל המערך המוחזר.

9. **`Graph::getWeight(unsigned int u, unsigned int v) const -> int`:**

   - מחזיר את משקל הקצה מקודקוד `u` לקודקוד `v`.

10. **אופרטורים אריתמטיים:**

    - **תוספת (`+`):**

      - `אופרטור גרף+(const Graph& other) const`: מוסיף שני גרפים ביחד. לגרף המתקבל יש משקלי קצוות השווים לסכום משקלי הקצוות התואמים בגרפי הקלט.
      - `Graph& operator+=(const Graph& other)`: מוסיף גרף נוסף לגרף הנוכחי. הגרף הנוכחי שונה במקומו.

    - **חיסור (`-`):**

      - `אופרטור גרף-(const Graph& other) const`: מפחית גרף נוסף מהגרף הנוכחי. לגרף המתקבל יש משקלי קצוות השווים להפרש של משקלי הקצוות המתאימים בגרפי הקלט.
      - `Graph& operator-=(const Graph& other)`: מחסיר גרף נוסף מהגרף הנוכחי. הגרף הנוכחי שונה במקומו.

    - **Unary Plus (`+`):**

      - `אופרטור גרף+() const`: מחזיר את הגרף המקורי.

    - **מינוס אחד (`-`):**
      - `אופרטור גרף-() const`: שולל את כל משקלי הקצוות בגרף.

11. **מפעילי השוואה:**

    - `bool operator==(const Graph& other) const`: בודק אם שני גרפים שווים. שני גרפים נחשבים שווים אם מטריצות הסמיכות שלהם זהות.
    - `bool operator!=(const Graph& other) const`: בודק אם שני גרפים אינם שווים.
    - `bool operator<(const Graph& other) const`: משווה בין שני גרפים על סמך מספר הקצוות והקודקודים. אם מספר הקצוות שווה, הגרף עם פחות קודקודים נחשב פחות מהשני.
    - `bool operator<=(const Graph& other) const`: בודק אם גרף אחד קטן או שווה לאחר.
    - `bool operator>(const Graph& other) const`: בודק אם גרף אחד גדול מהאחר.
    - `bool operator>=(const Graph& other) const`: בודק אם גרף אחד גדול או שווה לאחר.

12. **הגדלה והקטנה של אופרטורים:**

    - **תוספת קידומת (`++`):**

      - `Graph& operator++()`: מגדיל את כל משקלי הקצוות בגרף ב-1.
      - `אופרטור גרף++(int)`: מגדיל את כל משקלי הקצוות בגרף ב-1, ומחזיר את הגרף המקורי.

    - **הקטנת קידומת (`--`):**
      - `Graph& operator--()`: מקטין את כל משקלי הקצוות בגרף ב-1.
      - `אופרטור גרף--(int)`: מקטין את כל משקלי הקצוות בגרף ב-1, ומחזיר את הגרף המקורי.

13. **כפל סקלארי :**

    - `אופרטור גרף*(int scalar) const`: מכפיל את הגרף בסקלר. לגרף המתקבל יש משקלי קצה השווים למכפלת הסקלר ומשקולות הקצה המקוריות.
    - `Graph& operator*=(int scalar)`: מכפיל את הגרף בסקלר. הגרף הנוכחי שונה במקומו.

14. **כפל גרפים:**

    - `אופרטור גרף*(const Graph& other) const`: מבצע כפל גרפים. הגרף המתקבל מייצג את ההרכב של שני גרפי הקלט.

15. **מחלקה סקלרית:**
    - `אופרטור גרף/(int scalar) const`: מחלק את כל משקלי הקצוות בגרף בסקלר.
    - `Graph& operator/=(int scalar)`: מחלק את כל משקלי הקצוות בגרף בסקלאר.
