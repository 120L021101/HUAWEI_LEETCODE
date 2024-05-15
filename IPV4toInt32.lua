local function int2bit(num)
    num = num + 0
    local bitStr = ""

    while num ~= 0 do
        if num % 2 == 1 then
            bitStr = "1" .. bitStr
        else
            bitStr = "0" .. bitStr
        end
        num = num // 2
    end

    while string.len(bitStr) ~= 8 do
        bitStr = "0" .. bitStr
    end
    return bitStr
end

local function bit2int(bitStr)
    local num = 0
    for i = 1, #bitStr do
        if string.sub(bitStr, i, i) == "1" then
            num = num * 2 + 1;
        else
            num = num * 2;
        end
    end
    return num
end

local function ip_to_int32(ip)
    -- Implement me! :D
    local mergedBitStr = ""
    for bitStr in string.gmatch(ip, "([^.]+)", 1) do
        mergedBitStr = mergedBitStr .. int2bit(bitStr)
    end
    return bit2int(mergedBitStr)
end


return ip_to_int32