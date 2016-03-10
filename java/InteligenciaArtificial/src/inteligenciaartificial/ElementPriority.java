/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package inteligenciaartificial;

import java.awt.Point;

/**
 *
 * @author danielfms
 */
public class ElementPriority implements Comparable<ElementPriority> {
    Point pos;
    int weight;
    
    public ElementPriority(Point _pos, int _w){
        pos = _pos;
        weight = _w;
    }

    @Override public int compareTo(ElementPriority other) {
        return Integer.compare(this.weight, other.weight);
    }
}
