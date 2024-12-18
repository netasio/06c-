
function getSeniales() {
    const señales = [];
    for (let i = 0; i < 20; i++) {
        const señal = Math.floor(Math.random() * 400) - 10; 
        if (señal < 0) break;
        señales.push(señal % 360); 
    }
    return señales;
}

function getCuadrantes(señales) {
    return señales.map(señal => {
        if (señal >= 0 && señal < 90) return 'N';
        if (señal >= 90 && señal < 180) return 'E';
        if (señal >= 180 && señal < 270) return 'S';
        return 'O';
    }).join('');
}

function contarCiclos(cuadrantes) {
    const ciclos = ['NESO', 'OSEN', 'ESON', 'SENO', 'SONE', 'ENOS', 'ONES', 'NOSE'];
    let conteo = 0;
    for (let i = 0; i <= cuadrantes.length - 4; i++) {
        const secuencia = cuadrantes.substring(i, i + 4);
        if (ciclos.includes(secuencia)) conteo++;
    }
    return conteo;
}

function calcularPorcentajes(cuadrantes) {
    const total = cuadrantes.length;
    const ocurrencias = { 'N': 0, 'E': 0, 'S': 0, 'O': 0 };
    for (const char of cuadrantes) {
        if (ocurrencias[char] !== undefined) ocurrencias[char]++;
    }
    for (const cuadrante in ocurrencias) {
        ocurrencias[cuadrante] = ((ocurrencias[cuadrante] / total) * 100).toFixed(2);
    }
    return ocurrencias;
}

function main() {
    const señales = getSeniales();
    console.log("Señales:", señales);

    const cuadrantes = getCuadrantes(señales);
    console.log("Secuencia de cuadrantes:", cuadrantes);

    const ciclosCompletos = contarCiclos(cuadrantes);
    console.log("Cantidad de ciclos completos:", ciclosCompletos);

    const porcentajes = calcularPorcentajes(cuadrantes);
    console.log("Porcentajes de ocurrencias por cuadrante:", porcentajes);
}

main();
