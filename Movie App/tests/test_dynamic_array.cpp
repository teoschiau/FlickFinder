//
// Created by Teodora Schiau on 23.03.2024.
//

#include "test_dynamic_array.h"
#include "DynamicArray.h"
#include <assert.h>

void Test_DynamicArray::test_resize() {

    DynamicArray<int>* DA = new DynamicArray<int>(2);
    DA->add_element(1);
    DA->add_element(2);
    DA->add_element(3);
    assert(DA->get_size() == 3);
    delete DA;
}
void Test_DynamicArray::test_add() {

    DynamicArray<int>* da = new DynamicArray<int>(5);
    da->add_element(1);
    da->add_element(2);
    da->add_element(3);
    assert(da->get_size()==3);
    assert((*da)[0]==1);
    delete da;

}
void Test_DynamicArray::test_remove() {
    DynamicArray<int>* da = new DynamicArray<int>(5);
    da->add_element(1);
    da->add_element(2);
    da->add_element(3);
    assert(da->get_size()==3);
    da->delete_element(1);
    assert(da->get_size()==2);
    da->delete_element(2);
    assert(da->get_size()==1);
    assert((*da)[0]==1);
    delete da;
}
void Test_DynamicArray::test_update() {
    DynamicArray<int>* da = new DynamicArray<int>(5);
    da->add_element(1);
    da->add_element(2);
    da->add_element(3);
    assert(da->get_size()==3);
    da->update(4,1);
    assert((*da)[1]==4);
    delete da;
}
void Test_DynamicArray::test_all()
{
    test_resize();
    test_add();
    test_remove();
    test_update();
}