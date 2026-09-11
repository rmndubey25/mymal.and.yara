rule Safe_Malware_Simulator
{
    meta:
        description = "Detects the Malware Simulator"
        author = "Raman"
        purpose = "to have fun"

    strings:
        $key = "MJisKUCHUPUCHU"
        $enc = "Encrypted file created!"
        $done = "Simulation complete."

    condition:
        2 of them
}
