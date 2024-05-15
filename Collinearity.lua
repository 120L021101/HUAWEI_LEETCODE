local function collinearity(x1, y1, x2, y2)
    -----------------------
    -- x  y  z
    -- x1 y1 0
    -- x2 y2 0
    -- x1y2 - x2y1 = z
    -----------------------
    return (x1 * y2 - x2 * y1) == 0
end

return collinearity