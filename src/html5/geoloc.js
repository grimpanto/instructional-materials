var options = {
            enableHighAccuracy: true,
            timeout: 1000, // legt max. Wartezeit fest
            maximumAge: 0 // max. akzeptiertes Cache-Alter
        }

        function successCallback(pos) {
            alert("Position " + pos);
        }

